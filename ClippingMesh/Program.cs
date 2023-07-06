using ClipperLib;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClippingMesh
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<IntPoint> subjectPolygon = new List<IntPoint>()
    {
        PolygonOperations.ToIntPoint(0, 0),
        PolygonOperations.ToIntPoint(10, 0),
        PolygonOperations.ToIntPoint(10, 10),
        PolygonOperations.ToIntPoint(0, 10)
    };

            List<IntPoint> holePolygon = new List<IntPoint>()
    {
        PolygonOperations.ToIntPoint(4, 4),
        PolygonOperations.ToIntPoint(6, 4),
        PolygonOperations.ToIntPoint(6, 6),
        PolygonOperations.ToIntPoint(4, 6)
    };

            List<IntPoint> resultPolygon =
                PolygonOperations.MakeHoleInPolygon(subjectPolygon, holePolygon);

            // Do something with resultPolygon

            return;
        }
    }

    public class PolygonOperations
    {
        private const int MultiplyFactor = 1000; // to handle precision in ClipperLib

        public static List<IntPoint> MakeHoleInPolygon(
            List<IntPoint> subjectPolygon,
            List<IntPoint> holePolygon)
        {
            Clipper c = new Clipper();
            c.AddPath(subjectPolygon, PolyType.ptSubject, true);
            c.AddPath(holePolygon, PolyType.ptClip, true);

            List<List<IntPoint>> solution = new List<List<IntPoint>>();
            c.Execute(ClipType.ctDifference, solution,
                PolyFillType.pftNonZero,
                PolyFillType.pftNonZero);

            // Assuming only one polygon with one or more holes
            List<IntPoint> outerEdges = solution[0];

            // This is where you should connect outer edges with holes
            // assuming the first hole is at index 1.
            if (solution.Count > 1)
            {
                List<IntPoint> holeEdges = solution[1];

                // Here you should find the closest points between outer edges and hole
                // This is just an example and won't work in a real application.
                // You should replace it with appropriate algorithm or library
                IntPoint closestOuterEdgePoint = outerEdges[0];
                IntPoint closestHoleEdgePoint = holeEdges[0];

                // Connect outer edge with the hole
                outerEdges.Add(closestHoleEdgePoint);
                outerEdges.AddRange(holeEdges);
                outerEdges.Add(closestOuterEdgePoint); // back to the outer edge
            }

            return outerEdges;
        }

        public static IntPoint ToIntPoint(double x, double y)
        {
            return new IntPoint(x * MultiplyFactor, y * MultiplyFactor);
        }
    }
}
