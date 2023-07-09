using ClipperLib;
using NetTopologySuite.Geometries;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using Point = System.Drawing.Point;

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

        public static Point[] CreatePolygonWithHole(Point[] outerPolygonPoints, Point[] holePolygonPoints)
        {
            // NetTopologySuiteのCoordinate型に変換
            var outerCoordinates = outerPolygonPoints.Select(p => new Coordinate(p.X, p.Y)).ToArray();
            var holeCoordinates = holePolygonPoints.Select(p => new Coordinate(p.X, p.Y)).ToArray();

            // 新しいポリゴンを生成
            var outerRing = new LinearRing(outerCoordinates);
            var holes = new[] { new LinearRing(holeCoordinates) };
            var polygonWithHole = new Polygon(outerRing, holes);

            // 結果のPoint配列を生成
            var resultPoints = new List<Point>();
            foreach (var coordinate in polygonWithHole.Coordinates)
            {
                resultPoints.Add(new Point((int)coordinate.X, (int)coordinate.Y));
            }

            return resultPoints.ToArray();
        }

        //public static Point[] CreatePolygonWithMultipleHoles(Point[] outerPolygonPoints, List<Point[]> holePolygonPointsList)
        //{
        //    // NetTopologySuiteのCoordinate型に変換
        //    var outerCoordinates = outerPolygonPoints.Select(p => new Coordinate(p.X, p.Y)).ToArray();
        //    var holeCoordinatesList = holePolygonPointsList.Select(holePolygonPoints => holePolygonPoints.Select(p => new Coordinate(p.X, p.Y)).ToArray()).ToList();

        //    // 新しいポリゴンを生成
        //    var outerRing = new LinearRing(outerCoordinates);
        //    var holes = holeCoordinatesList.Select(holeCoordinates => new LinearRing(holeCoordinates)).ToArray();
        //    var polygonWithHoles = new Polygon(outerRing, holes);

        //    // 結果のPoint配列を生成
        //    var resultPoints = new List<Point>();
        //    foreach (var coordinate in polygonWithHoles.Coordinates)
        //    {
        //        resultPoints.Add(new Point((int)coordinate.X, (int)coordinate.Y));
        //    }

        //    return resultPoints.ToArray();
        //}

        public static Point[] CreatePolygonWithHoles(Point[] outer, List<Point[]> holes)
        {
            // Create outer LinearRing
            var outerCoordinates = outer.Select(p => new Coordinate(p.X, p.Y)).ToArray();
            var outerLinearRing = new LinearRing(outerCoordinates);

            // Create holes LinearRings
            var holeLinearRings = holes.Select(hole =>
            {
                var holeCoordinates = hole.Select(p => new Coordinate(p.X, p.Y)).ToArray();
                return new LinearRing(holeCoordinates);
            }).ToArray();

            // Create polygon with holes
            var polygon = new Polygon(outerLinearRing, holeLinearRings);

            // Create resulting polygon (with holes subtracted)
            var resultingPolygon = polygon.Buffer(0); // This operation 'cleans' the polygon, uniting its parts and subtracting holes

            // Transform resulting polygon to array of Points and return it
            var resultingPoints = resultingPolygon.Coordinates.Select(c => new Point((int)c.X, (int)c.Y)).ToArray();
            return resultingPoints;
        }
    }
}
