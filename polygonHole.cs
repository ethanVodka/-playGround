using System;
using System.Collections.Generic;

//...

List<(double, double)> coords = new List<(double, double)> {
    (0, 0), (5, 0), (5, 5), (0, 5), (0, 0),
    (2, 2), (2, 3), (3, 3), (3, 2), (2, 2)
};

public static void GetPolygonsHole()
{
    List<List<(double, double)>> allRings = new List<List<(double, double)>>();
    List<(double, double)> currentRing = new List<(double, double)>();

    foreach (var coord in coords)
    {
        currentRing.Add(coord);

     if (currentRing.Count > 1 && coord == currentRing[0])
       {
           allRings.Add(currentRing);
            currentRing = new List<(double, double)>();
        }
    }

    // 最初のリングが外部ループで、それ以降のリングがホール
    List<(double, double)> exteriorRing = allRings[0];
    List<List<(double, double)>> interiorRings = allRings.GetRange(1, allRings.Count - 1);
}

double CalculatePolygonArea(List<(double, double)> polygon)
{
    double area = 0;

    for (int i = 0; i < polygon.Count; i++)
    {
        (double x1, double y1) = polygon[i];
        (double x2, double y2) = polygon[(i + 1) % polygon.Count];
        area += (x1 * y2) - (x2 * y1);
    }

    return Math.Abs(area / 2.0);
}