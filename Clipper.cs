static void Main(string[] args)
    {
        List<IntPoint> complexPoly = new List<IntPoint>
        {
            new IntPoint(0,0),
            new IntPoint(50,50),
            new IntPoint(0,100),
            new IntPoint(100,100),
            new IntPoint(50,50),
            new IntPoint(100,0)
        };

        List<List<IntPoint>> polygon = new List<List<IntPoint>> { complexPoly };

        // Simplify the polygon.
        List<List<IntPoint>> simplified = Clipper.SimplifyPolygons(polygon, PolyFillType.pftEvenOdd);

        // Filter out any holes with area less than 1000.
        double minHoleArea = 1000.0;
        List<List<IntPoint>> result = new List<List<IntPoint>>();
        foreach (List<IntPoint> contour in simplified)
        {
            double area = Math.Abs(Clipper.Area(contour));
            if (Clipper.Orientation(contour) || area >= minHoleArea)
            {
                result.Add(contour);
            }
        }

        // Print out the resulting polygon.
        foreach (List<IntPoint> contour in result)
        {
            Console.WriteLine("New contour:");
            foreach (IntPoint pt in contour)
            {
                Console.WriteLine($"{pt.X}, {pt.Y}");
            }
        }
    }

    static void Main(string[] args)
    {
        List<IntPoint> outer = new List<IntPoint>
        {
            new IntPoint(0,0),
            new IntPoint(0,70),
            new IntPoint(10,70),
            new IntPoint(10,10),
            new IntPoint(20,10),
            new IntPoint(20,30),
            new IntPoint(10,30),
            new IntPoint(10,40),
            new IntPoint(20,40),
            new IntPoint(20,50),
            new IntPoint(10,50),
            new IntPoint(10,60),
            new IntPoint(30,60),
            new IntPoint(30,0),
        };

        List<List<IntPoint>> polygon = new List<List<IntPoint>> { outer };

        // TODO: Add any holes to the 'polygon' list here.

        // Simplify the polygon.
        List<List<IntPoint>> simplified = Clipper.SimplifyPolygons(polygon, PolyFillType.pftNonZero);

        // Filter out any holes with area less than 1000.
        double minHoleArea = 1000.0;
        List<List<IntPoint>> result = new List<List<IntPoint>>();
        foreach (List<IntPoint> contour in simplified)
        {
            double area = Math.Abs(Clipper.Area(contour));
            if (Clipper.Orientation(contour) || area >= minHoleArea)
            {
                result.Add(contour);
            }
        }

        // Print out the resulting polygon.
        foreach (List<IntPoint> contour in result)
        {
            Console.WriteLine("New contour:");
            foreach (IntPoint pt in contour)
            {
                Console.WriteLine($"{pt.X}, {pt.Y}");
            }
        }
    }

    static void Main(string[] args)
    {
        List<IntPoint> poly = new List<IntPoint>
        {
            new IntPoint(10,10),
            new IntPoint(110,10),
            new IntPoint(110,110),
            new IntPoint(10,110)
        };

        double offset = 20.0;  // Amount to offset the polygon.

        ClipperOffset co = new ClipperOffset();
        co.AddPath(poly, JoinType.jtSquare, EndType.etClosedPolygon);
        List<List<IntPoint>> solution = new List<List<IntPoint>>();
        co.Execute(ref solution, offset);

        // Print out the resulting polygon.
        foreach (List<IntPoint> contour in solution)
        {
            Console.WriteLine("New contour:");
            foreach (IntPoint pt in contour)
            {
                Console.WriteLine($"{pt.X}, {pt.Y}");
            }
        }
    }

    static void Main(string[] args)
    {
        List<IntPoint> poly1 = new List<IntPoint>
        {
            new IntPoint(10,10),
            new IntPoint(110,10),
            new IntPoint(110,110),
            new IntPoint(10,110)
        };

        List<IntPoint> poly2 = new List<IntPoint>
        {
            new IntPoint(50,50),
            new IntPoint(150,50),
            new IntPoint(150,150),
            new IntPoint(50,150)
        };

        Clipper c = new Clipper();
        c.AddPath(poly1, PolyType.ptSubject, true);
        c.AddPath(poly2, PolyType.ptClip, true);

        List<List<IntPoint>> solution = new List<List<IntPoint>>();
        c.Execute(ClipType.ctIntersection, solution, PolyFillType.pftEvenOdd, PolyFillType.pftEvenOdd);

        // Print out the resulting polygon.
        foreach (List<IntPoint> contour in solution)
        {
            Console.WriteLine("New contour:");
            foreach (IntPoint pt in contour)
            {
                Console.WriteLine($"{pt.X}, {pt.Y}");
            }
        }
    }

    static void Main(string[] args)
    {
        List<IntPoint> poly = new List<IntPoint>
        {
            new IntPoint(12,12),
            new IntPoint(113,18),
            new IntPoint(116,115),
            new IntPoint(14,109),
            new IntPoint(12,12),
            new IntPoint(60,60),
            new IntPoint(80,60),
            new IntPoint(80,80),
            new IntPoint(60,80)
        };

        double gridSpacing = 5.0;  // Grid spacing (5um).

        // Simplify the polygon.
        List<List<IntPoint>> simplifiedPoly = Clipper.SimplifyPolygon(poly, PolyFillType.pftEvenOdd);

        // Snap each contour of the simplified polygon to the grid.
        List<List<IntPoint>> gridPoly = new List<List<IntPoint>>();
        foreach (List<IntPoint> contour in simplifiedPoly)
        {
            List<IntPoint> gridContour = new List<IntPoint>();
            foreach (IntPoint pt in contour)
            {
                long x = (long)(Math.Round((double)pt.X / gridSpacing) * gridSpacing);
                long y = (long)(Math.Round((double)pt.Y / gridSpacing) * gridSpacing);
                gridContour.Add(new IntPoint(x, y));
            }
            gridPoly.Add(gridContour);
        }

        // Print out the resulting polygon.
        foreach (List<IntPoint> contour in gridPoly)
        {
            Console.WriteLine("New contour:");
            foreach (IntPoint pt in contour)
            {
                Console.WriteLine($"{pt.X}, {pt.Y}");
            }
        }
    }