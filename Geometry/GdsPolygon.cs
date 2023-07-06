using ClipperLib;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Geometry
{
    public class GdsPolygon
    {
        public Point[] Outer { get; set; }
        public List<Point[]> Holes { get; set; } = new List<Point[]>();
    }

    public class GdsPolygons
    {
        public static List<GdsPolygon> AnalyzePolygons(List<Point[]> outerPolygons, List<Point[]> holePolygons)
        {
            var gdsPolygons = new List<GdsPolygon>();

            foreach (var outerPolygon in outerPolygons)
            {
                var gdsPolygon = new GdsPolygon { Outer = outerPolygon };

                var outerIntPolygon = outerPolygon.Select(p => new IntPoint(p.X, p.Y)).ToList();

                foreach (var holePolygon in holePolygons)
                {
                    var holeIntPolygon = holePolygon.Select(p => new IntPoint(p.X, p.Y)).ToList();

                    // if the hole is in the outer polygon
                    if (Clipper.PointInPolygon(holeIntPolygon[0], outerIntPolygon) != 0)
                    {
                        gdsPolygon.Holes.Add(holePolygon);
                    }
                }

                gdsPolygons.Add(gdsPolygon);
            }

            return gdsPolygons;
        }
    }
}
