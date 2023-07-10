using ClipperLib;
using NetTopologySuite.Geometries;
using NetTopologySuite.Operation.Overlay;
using NetTopologySuite.Operation.Overlay.Snap;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace Geometry
{
    public class UPoint
    {
        public double X { get; set; }
        public double Y { get; set; }

        public UPoint(double x, double y)
        {
            X = x;
            Y = y;
        }

        //public static Point[] CreatePolygonWithHole(Point[] outerPolygonPoints, Point[] holePolygonPoints)
        //{
        //    // NetTopologySuiteのCoordinate型に変換
        //    Coordinate[] outerCoordinates = outerPolygonPoints.Select(p => new Coordinate(p.X, p.Y)).ToArray();
        //    Coordinate[] holeCoordinates = holePolygonPoints.Select(p => new Coordinate(p.X, p.Y)).ToArray();

        //    // 新しいポリゴンを生成
        //    var outerRing = new LinearRing(outerCoordinates);
        //    var holes = new[] { new LinearRing(holeCoordinates) };
        //    var polygonWithHole = new Polygon(outerRing, holes);

        //    // 結果のPoint配列を生成
        //    var resultPoints = new List<Point>();
        //    foreach (var coordinate in polygonWithHole.Coordinates)
        //    {
        //        resultPoints.Add(new Point((int)coordinate.X, (int)coordinate.Y));
        //    }

        //    return resultPoints.ToArray();
        //}

        ////public static Point[] CreatePolygonWithMultipleHoles(Point[] outerPolygonPoints, List<Point[]> holePolygonPointsList)
        ////{
        ////    // NetTopologySuiteのCoordinate型に変換
        ////    var outerCoordinates = outerPolygonPoints.Select(p => new Coordinate(p.X, p.Y)).ToArray();
        ////    var holeCoordinatesList = holePolygonPointsList.Select(holePolygonPoints => holePolygonPoints.Select(p => new Coordinate(p.X, p.Y)).ToArray()).ToList();

        ////    // 新しいポリゴンを生成
        ////    var outerRing = new LinearRing(outerCoordinates);
        ////    var holes = holeCoordinatesList.Select(holeCoordinates => new LinearRing(holeCoordinates)).ToArray();
        ////    var polygonWithHoles = new Polygon(outerRing, holes);

        ////    // 結果のPoint配列を生成
        ////    var resultPoints = new List<Point>();
        ////    foreach (var coordinate in polygonWithHoles.Coordinates)
        ////    {
        ////        resultPoints.Add(new Point((int)coordinate.X, (int)coordinate.Y));
        ////    }

        ////    return resultPoints.ToArray();
        ////}

        //public static Point[] CreatePolygonWithHoles(Point[] outer, List<Point[]> holes)
        //{
        //    // Create outer LinearRing
        //    var outerCoordinates = outer.Select(p => new Coordinate(p.X, p.Y)).ToArray();
        //    var outerLinearRing = new LinearRing(outerCoordinates);

        //    // Create holes LinearRings
        //    var holeLinearRings = holes.Select(hole =>
        //    {
        //        var holeCoordinates = hole.Select(p => new Coordinate(p.X, p.Y)).ToArray();
        //        return new LinearRing(holeCoordinates);
        //    }).ToArray();

        //    // Create polygon with holes
        //    var polygon = new Polygon(outerLinearRing, holeLinearRings);

        //    // Create resulting polygon (with holes subtracted)
        //    var resultingPolygon = polygon.Buffer(0); // This operation 'cleans' the polygon, uniting its parts and subtracting holes

        //    // Transform resulting polygon to array of Points and return it
        //    var resultingPoints = resultingPolygon.Coordinates.Select(c => new Point((int)c.X, (int)c.Y)).ToArray();
        //    return resultingPoints;
        //}

        public static UPoint[] CreatePathWithMultipleHoles(UPoint[] outer, List<UPoint[]> holes)
        {
            var geometryFactory = new GeometryFactory();

            // Convert System.Drawing.Point to NetTopologySuite.Coordinate
            var outerCoords = outer.Select(p => new Coordinate(p.X, p.Y)).ToArray();

            // Create outer polygon
            var outerPolygon = new Polygon(new LinearRing(outerCoords));

            // Check and repair self-intersections in the outer polygon
            if (!outerPolygon.IsValid)
            {
                Polygon repairedOuterPolygon = (Polygon)new GeometrySnapper(outerPolygon).SnapToSelf(0.01, false); // Tolerance for snapping
                outerPolygon = repairedOuterPolygon;
            }

            // Convert outer polygon to points
            var polygonPoints = outerPolygon.Coordinates.Select(c => new UPoint(c.X, c.Y)).ToList();

            // Iterate over each hole and subtract from polygon
            for (int i = 0; i < holes.Count; i++)
            {
                UPoint[] hole = holes[i];
                // Convert System.Drawing.Point to NetTopologySuite.Coordinate for each hole
                var holeCoords = hole.Select(p => new Coordinate(p.X, p.Y)).ToArray();

                // Create hole polygon
                var holePolygon = new Polygon(new LinearRing(holeCoords));

                // Check and repair self-intersections in the hole polygon
                if (!holePolygon.IsValid)
                {
                    Polygon repairedHolePolygon = (Polygon)new GeometrySnapper(holePolygon).SnapToSelf(0.01, false); // Tolerance for snapping
                    holePolygon = repairedHolePolygon;
                }

                // Subtract hole from polygon and update polygonPoints
                polygonPoints = AddHoleToPolygon(polygonPoints.ToArray(), hole).ToList();

                // Add the first point at the end to close the polygon
                polygonPoints.Add(polygonPoints[0]);
                //if (i != holes.Count - 1)
                //{
                //}
            }

            return polygonPoints.ToArray();
        }

        public static UPoint[] AddHoleToPolygon(UPoint[] polygon, UPoint[] newHole)
        {
            // Convert System.Drawing.Point to NetTopologySuite.Coordinate
            var polygonCoords = polygon.Select(p => new Coordinate(p.X, p.Y)).ToArray();
            var holeCoords = newHole.Select(p => new Coordinate(p.X, p.Y)).ToArray();

            // create existing polygon and new hole polygon
            var existingPolygon = new Polygon(new LinearRing(polygonCoords));
            var newHolePolygon = new Polygon(new LinearRing(holeCoords));

            // Snap geometries to themselves
            existingPolygon = (Polygon)new GeometrySnapper(existingPolygon).SnapToSelf(0.01, true);
            newHolePolygon = (Polygon)new GeometrySnapper(newHolePolygon).SnapToSelf(0.01, false);

            // subtract new hole from the existing polygon
            var result = OverlayOp.Overlay(existingPolygon, newHolePolygon, SpatialFunction.Difference);

            // get the coordinates of the resulting polygon
            var resultCoordinates = result.Coordinates;

            // Convert back to System.Drawing.Point
            var resultPoints = resultCoordinates.Select(c => new UPoint(c.X, c.Y)).ToArray();

            return resultPoints;
        }
    }
}
