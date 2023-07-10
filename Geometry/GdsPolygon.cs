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
        public UPoint[] Outer { get; set; }
        public List<UPoint[]> Holes { get; set; } = new List<UPoint[]>();
    }

    public class GdsPolygons
    {
        public static List<GdsPolygon> AnalyzePolygons(List<UPoint[]> outerPolygons, List<UPoint[]> holePolygons, double scale = 1.0)
        {
            List<GdsPolygon> gdsPolygons = new List<GdsPolygon>();

            foreach (UPoint[] outerPolygon in outerPolygons)
            {
                GdsPolygon gdsPolygon = new GdsPolygon { Outer = outerPolygon };

                List<IntPoint> outerIntPolygon = outerPolygon.Select(p => new IntPoint(p.X * scale, p.Y * scale)).ToList();

                foreach (UPoint[] holePolygon in holePolygons)
                {
                    List<IntPoint> holeIntPolygon = holePolygon.Select(p => new IntPoint(p.X * scale, p.Y * scale)).ToList();

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
