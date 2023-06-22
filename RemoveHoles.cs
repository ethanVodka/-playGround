using System;
using System.Collections.Generic;
using ClipperLib;

class Program
{
    static void Main(string[] args)
    {
        List<IntPoint> poly = new List<IntPoint> { /* Add your points here. */ };

        double minHoleArea = 1000.0;  // Minimum hole area to keep.

        // Simplify the polygon.
        List<List<IntPoint>> simplifiedPoly = Clipper.SimplifyPolygon(poly, PolyFillType.pftEvenOdd);

        // Separate the contours into outer and holes.
        List<List<IntPoint>> outerContours = new List<List<IntPoint>>();
        List<List<IntPoint>> holeContours = new List<List<IntPoint>>();
        foreach (List<IntPoint> contour in simplifiedPoly)
        {
            if (Clipper.Orientation(contour))
            {
                outerContours.Add(contour);
            }
            else
            {
                holeContours.Add(contour);
            }
        }

        // Compute the area of each hole, and add those above the threshold to the new polygon.
        List<List<IntPoint>> newPoly = new List<List<IntPoint>>(outerContours);
        foreach (List<IntPoint> hole in holeContours)
        {
            double holeArea = Math.Abs(Clipper.Area(hole));
            if (holeArea > minHoleArea)
            {
                newPoly.Add(hole);
            }
        }

        // The newPoly now contains only the outer contours and the holes above the area threshold.
        // If you want a single contour polygon, you can perform a union operation.
        Clipper c = new Clipper();
        c.AddPaths(newPoly, PolyType.ptSubject, true);
        List<List<IntPoint>> resultPoly = new List<List<IntPoint>>();
        c.Execute(ClipType.ctUnion, resultPoly, PolyFillType.pftEvenOdd, PolyFillType.pftEvenOdd);

        // Print out the resulting polygon.
        foreach (List<IntPoint> contour in resultPoly)
        {
            foreach (IntPoint pt in contour)
            {
                Console.WriteLine($"{pt.X}, {pt.Y}");
            }
            Console.WriteLine();
        }
    }
}


using System;
using System.Collections.Generic;
using TriangleNet.Geometry;
using TriangleNet.Topology.DCEL;

class Program
{
    static void Main(string[] args)
    {
        // Create a new polygon.
        Polygon polygon = new Polygon();

        // Add points to the polygon.
        polygon.Add(new Vertex(0, 0));
        polygon.Add(new Vertex(0, 70));
        polygon.Add(new Vertex(10, 70));
        polygon.Add(new Vertex(10, 10));
        polygon.Add(new Vertex(20, 10));
        polygon.Add(new Vertex(20, 30));
        polygon.Add(new Vertex(10, 30));
        polygon.Add(new Vertex(10, 40));
        polygon.Add(new Vertex(20, 40));
        polygon.Add(new Vertex(20, 50));
        polygon.Add(new Vertex(10, 50));
        polygon.Add(new Vertex(10, 60));
        polygon.Add(new Vertex(30, 60));
        polygon.Add(new Vertex(30, 0));

        // Generate the triangulation.
        var mesh = polygon.Triangulate();

        // Print out the resulting triangles.
        foreach (Triangle triangle in mesh.Triangles)
        {
            Console.WriteLine($"Triangle: ({triangle.GetVertex(0).X}, {triangle.GetVertex(0).Y}), ({triangle.GetVertex(1).X}, {triangle.GetVertex(1).Y}), ({triangle.GetVertex(2).X}, {triangle.GetVertex(2).Y})");
        }
    }
}
