using NetTopologySuite.Geometries;
using NetTopologySuite.Operation.Distance;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using Point = System.Drawing.Point;

namespace Geometry
{
    public class Topology
    {

        public static Point[] CreateSingleStrokePath(Point[] outer, List<Point[]> holes)
        {
            // Convert input to NTS format
            Coordinate[] outerCoordinates = new Coordinate[outer.Length + 1];
            for (int i = 0; i < outer.Length; i++)
            {
                outerCoordinates[i] = new Coordinate(outer[i].X, outer[i].Y);
            }
            outerCoordinates[outerCoordinates.Length - 1] = new Coordinate(outer[0].X, outer[0].Y);
            Polygon outerPolygon = new Polygon(new LinearRing(outerCoordinates));

            List<Polygon> holePolygons = new List<Polygon>();
            foreach (var hole in holes)
            {
                Coordinate[] holeCoordinates = new Coordinate[hole.Length + 1];
                for (int i = 0; i < hole.Length; i++)
                {
                    holeCoordinates[i] = new Coordinate(hole[i].X, hole[i].Y);
                }
                holeCoordinates[holeCoordinates.Length - 1] = new Coordinate(hole[0].X, hole[0].Y);

                holePolygons.Add(new Polygon(new LinearRing(holeCoordinates)));
            }

            // ここから
            ////////////////////////////////////////////////////////////////////////////////////////////////

            // Coordinate list for the final single stroke path
            List<Coordinate> singleStrokeCoordinates = new List<Coordinate>(outerPolygon.ExteriorRing.Coordinates);

            // Find closest points between outer polygon and each hole, and sort by distance
            var holeDistances = new List<(Polygon hole, Coordinate[] closestPoints, double distance)>();

            foreach (Polygon hole in holePolygons)
            {
                Coordinate[] closestPoints = FindClosestPoints(outerPolygon, hole);
                double distance = closestPoints[0].Distance(closestPoints[1]);
                holeDistances.Add((hole, closestPoints, distance));
            }

            holeDistances.Sort((a, b) => a.distance.CompareTo(b.distance));

            // Insert hole paths in order of increasing distance to the outer polygon
            foreach (var holeInfo in holeDistances)
            {
                // Get indexes of the closest points
                int outerIndex = Array.FindIndex(outerPolygon.ExteriorRing.Coordinates, coord => coord.Equals2D(holeInfo.closestPoints[0]));
                int holeIndex = Array.FindIndex(holeInfo.hole.ExteriorRing.Coordinates, coord => coord.Equals2D(holeInfo.closestPoints[1]));

                // Insert hole coordinates at the location of the closest point on the outer polygon
                singleStrokeCoordinates.InsertRange(outerIndex, GetCoordinatesInOrder(holeInfo.hole, holeIndex));
            }

            // Convert back to Point format
            return singleStrokeCoordinates.Select(c => new Point((int)c.X, (int)c.Y)).ToArray();
        }

        private static IEnumerable<Coordinate> GetCoordinatesInOrder(Polygon polygon, int startIndex)
        {
            List<Coordinate> coordinates = new List<Coordinate>(polygon.Coordinates);
            Rotate(coordinates, startIndex);
            return coordinates;
        }

        private static void Rotate<T>(List<T> list, int offset)
        {
            if (offset != 0)
            {
                T[] copy = new T[list.Count];
                list.CopyTo(copy);

                for (int i = 0; i < list.Count; i++)
                {
                    int index = (i + offset) % list.Count;
                    list[i] = copy[index];
                }
            }
        }

        private static Coordinate[] FindClosestPoints(Polygon outer, Polygon hole)
        {
            double minDistance = double.MaxValue;
            Coordinate[] closestPoints = new Coordinate[2];

            foreach (Coordinate outerCoord in outer.ExteriorRing.Coordinates)
            {
                foreach (Coordinate holeCoord in hole.ExteriorRing.Coordinates)
                {
                    double distance = outerCoord.Distance(holeCoord);

                    if (distance < minDistance)
                    {
                        minDistance = distance;
                        closestPoints[0] = outerCoord;
                        closestPoints[1] = holeCoord;
                    }
                }
            }

            return closestPoints;
        }
    }
}
