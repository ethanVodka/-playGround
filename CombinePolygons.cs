using ClipperLib;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

public static List<List<IntPoint>> CombinePolygons(List<PointF[]> polygons, double scaleFactor = 1.0)
{
    // Initialize Clipper
    Clipper clipper = new Clipper();

    // Scale up coordinates and add polygons to clipper
    foreach (PointF[] polygon in polygons)
    {
        List<IntPoint> intPolygon = polygon
            .Select(p => new IntPoint(p.X * scaleFactor, p.Y * scaleFactor))
            .ToList();
        clipper.AddPath(intPolygon, PolyType.ptSubject, true); // true for closed polygons
    }

    // Execute union operation
    List<List<IntPoint>> result = new List<List<IntPoint>>();
    clipper.Execute(ClipType.ctUnion, result, PolyFillType.pftNonZero, PolyFillType.pftNonZero);

    // Scale down coordinates
    for (int i = 0; i < result.Count; i++)
    {
        result[i] = result[i]
            .Select(p => new IntPoint(p.X / scaleFactor, p.Y / scaleFactor))
            .ToList();
    }

    return result;
}

public static List<List<IntPoint>> SubtractPolygons(List<PointF[]> subjectPolygons, List<PointF[]> clipPolygons, double scaleFactor = 1.0)
{
    // Initialize Clipper
    Clipper clipper = new Clipper();

    // Scale up coordinates and add subject polygons to clipper
    foreach (PointF[] polygon in subjectPolygons)
    {
        List<IntPoint> intPolygon = polygon
            .Select(p => new IntPoint(p.X * scaleFactor, p.Y * scaleFactor))
            .ToList();
        clipper.AddPath(intPolygon, PolyType.ptSubject, true); // true for closed polygons
    }

    // Scale up coordinates and add clip polygons to clipper
    foreach (PointF[] polygon in clipPolygons)
    {
        List<IntPoint> intPolygon = polygon
            .Select(p => new IntPoint(p.X * scaleFactor, p.Y * scaleFactor))
            .ToList();
        clipper.AddPath(intPolygon, PolyType.ptClip, true); // true for closed polygons
    }

    // Execute difference operation
    List<List<IntPoint>> result = new List<List<IntPoint>>();
    clipper.Execute(ClipType.ctDifference, result, PolyFillType.pftEvenOdd, PolyFillType.pftEvenOdd);

    // Scale down coordinates
    for (int i = 0; i < result.Count; i++)
    {
        result[i] = result[i]
            .Select(p => new IntPoint((long)(p.X / scaleFactor), (long)(p.Y / scaleFactor)))
            .ToList();
    }

    return result;
}

public static List<List<IntPoint>> MergeClosePolygons(List<PointF[]> polygons, double distance, double scaleFactor = 1.0)
{
    // Initialize Clipper
    ClipperOffset offset = new ClipperOffset();
    Clipper clipper = new Clipper();

    // Scale up coordinates and add polygons to offsetter
    foreach (PointF[] polygon in polygons)
    {
        List<IntPoint> intPolygon = polygon
            .Select(p => new IntPoint(p.X * scaleFactor, p.Y * scaleFactor))
            .ToList();
        offset.AddPath(intPolygon, JoinType.jtSquare, EndType.etClosedPolygon);
    }

    // Expand polygons
    List<List<IntPoint>> offsetPolygons = new List<List<IntPoint>>();
    offset.Execute(ref offsetPolygons, distance * scaleFactor);

    // Add offset polygons to clipper
    foreach (List<IntPoint> polygon in offsetPolygons)
    {
        clipper.AddPath(polygon, PolyType.ptSubject, true);
    }

    // Execute union operation
    List<List<IntPoint>> result = new List<List<IntPoint>>();
    clipper.Execute(ClipType.ctUnion, result, PolyFillType.pftNonZero, PolyFillType.pftNonZero);

    // Scale down coordinates
    for (int i = 0; i < result.Count; i++)
    {
        result[i] = result[i]
            .Select(p => new IntPoint((long)(p.X / scaleFactor), (long)(p.Y / scaleFactor)))
            .ToList();
    }

    return result;
}
