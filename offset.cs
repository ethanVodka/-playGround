using System;
using System.Drawing;
using System.Windows.Forms;
using ClipperLib;
using System.Collections.Generic;
using System.Linq;

public class PolygonForm : Form
{
    private List<List<Point>> polygons;

    public PolygonForm(List<List<Point>> polygons)
    {
        this.polygons = polygons;
        this.DoubleBuffered = true;
    }

    protected override void OnPaint(PaintEventArgs e)
    {
        base.OnPaint(e);

        e.Graphics.Clear(Color.White);

        // Adjust the scale factor for suitable enlargement.
        float scaleFactor = 10.0f;

        // Use ScaleTransform to scale the graphics object.
        e.Graphics.ScaleTransform(scaleFactor, scaleFactor);

        foreach (var polygon in polygons)
        {
            e.Graphics.DrawPolygon(Pens.Black, polygon.ToArray());
        }
    }

    private static List<Point> ConvertToIntPointList(Path path, double scale)
    {
        return path.Select(ip => new Point((int)(ip.X / scale), (int)(ip.Y / scale))).ToList();
    }

    public static void Main()
    {
        // Define your polygons here.
        Paths subjectPolygons = new Paths();
        Paths clipPolygons = new Paths();

        // Populate polygons ...

        Clipper clipper = new Clipper();
        clipper.AddPaths(subjectPolygons, PolyType.ptSubject, true);
        clipper.AddPaths(clipPolygons, PolyType.ptClip, true);
        
        Paths solution = new Paths();
        clipper.Execute(ClipType.ctUnion, solution);

        var polygons = solution.Select(path => ConvertToIntPointList(path, 1)).ToList();

        Application.Run(new PolygonForm(polygons));
    }
}
