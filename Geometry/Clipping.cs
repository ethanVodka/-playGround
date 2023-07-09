using ClipperLib;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Geometry
{
    public class Clipping
    {
        /// <summary>
        /// Pathから閉じたポリゴン群へ変換
        /// </summary>
        /// <param name="polygons"></param>
        /// <returns></returns>
        public static List<Point[]> CombinePolygons(List<Point[]> polygons)
        {
            Clipper clipper = new Clipper();

            foreach (var polygon in polygons)
            {
                var path = polygon.Select(p => new IntPoint(p.X, p.Y)).ToList();
                // true means the path is closed
                clipper.AddPath(path, PolyType.ptSubject, true);
            }

            List<List<IntPoint>> resultPolygons = new List<List<IntPoint>>();
            clipper.Execute(ClipType.ctUnion, resultPolygons, PolyFillType.pftNonZero, PolyFillType.pftNonZero);

            List<Point[]> finalPolygons = resultPolygons.Select(p => p.Select(ip => new Point((int)ip.X, (int)ip.Y)).ToArray()).ToList();

            return finalPolygons;
        }

        /// <summary>
        /// ホールとそれ以外に分ける
        /// </summary>
        /// <param name="polygons"></param>
        /// <param name="polygonsWithHoles"></param>
        /// <param name="polygonsWithoutHoles"></param>
        public static void DividePolygons(List<Point[]> polygons, out List<Point[]> polygonsWithHoles, out List<Point[]> polygonsWithoutHoles)
        {
            polygonsWithHoles = new List<Point[]>();
            polygonsWithoutHoles = new List<Point[]>();

            foreach (var polygon in polygons)
            {
                List<IntPoint> intPolygon = new List<IntPoint>();

                foreach (var point in polygon)
                {
                    intPolygon.Add(new IntPoint(point.X, point.Y));
                }

                if (Clipper.Orientation(intPolygon))
                {
                    Point[] updatedPoints = new Point[polygon.Length + 1];

                    // 既存の要素を新しい配列にコピーする
                    Array.Copy(polygon, updatedPoints, polygon.Length);

                    // 新しい配列の最後の位置に新たな要素を追加する
                    updatedPoints[updatedPoints.Length - 1] = polygon[0];
                    
                    polygonsWithoutHoles.Add(updatedPoints);
                }
                else
                {
                    Point[] updatedPoints = new Point[polygon.Length + 1];

                    // 既存の要素を新しい配列にコピーする
                    Array.Copy(polygon, updatedPoints, polygon.Length);

                    // 新しい配列の最後の位置に新たな要素を追加する
                    updatedPoints[updatedPoints.Length - 1] = polygon[0];

                    polygonsWithHoles.Add(updatedPoints);
                }
            }
        }

        /// <summary>
        /// ホールかどうか判別
        /// </summary>
        /// <param name="polygon"></param>
        /// <returns></returns>
        public static bool IsHole(Point[] polygon)
        {
            List<IntPoint> points = new List<IntPoint>();
            points = polygon.Select(p => new IntPoint(p.X, p.Y)).ToList();

            if (Clipper.Orientation(points))
            {
                // is edge
                return false;
            }
            else
            {
                // is hole
                return true;
            }
        }

        /// <summary>
        /// ポリゴンの面積が閾値以上がどうか判断
        /// </summary>
        /// <param name="polygons"></param>
        /// <param name="minArea"></param>
        /// <returns></returns>
        public List<Point[]> FilterPolygonsByArea(List<Point[]> polygons, List<Point[]> holesForFill,double minArea)
        {
            List<Point[]> result = new List<Point[]>();

            foreach (var polygon in polygons)
            {
                var path = polygon.Select(p => new IntPoint(p.X, p.Y)).ToList();
                double area = Clipper.Area(path);

                if (area >= minArea)
                {
                    result.Add(polygon);
                }
                else
                {
                    holesForFill.Add(polygon);
                }
            }

            return result;
        }

        /// <summary>
        /// 閉じたパスを生成
        /// </summary>
        /// <param name="outerPolygon"></param>
        /// <param name="hole"></param>
        /// <returns></returns>
        public static List<Point[]> CreateClosedPathWithHole(Point[] outerPolygon, Point[] hole)
        {
            Clipper clipper = new Clipper();

            var outerPath = outerPolygon.Select(p => new IntPoint(p.X, p.Y)).ToList();
            var holePath = hole.Select(p => new IntPoint(p.X, p.Y)).ToList();

            clipper.AddPath(outerPath, PolyType.ptSubject, true);
            clipper.AddPath(holePath, PolyType.ptSubject, true);

            List<List<IntPoint>> resultPaths = new List<List<IntPoint>>();
            clipper.Execute(ClipType.ctUnion, resultPaths, PolyFillType.pftEvenOdd, PolyFillType.pftEvenOdd);

            List<Point[]> finalPaths = resultPaths.Select(p => p.Select(ip => new Point((int)ip.X, (int)ip.Y)).ToArray()).ToList();

            return finalPaths;
        }

        public static Point[] CreateSingleStrokePathWithHole(Point[] outerPolygon, Point[] hole)
        {
            var outerPath = outerPolygon.Select(p => new IntPoint(p.X, p.Y)).ToList();
            var holePath = hole.Select(p => new IntPoint(p.X, p.Y)).ToList();

            // Assuming the last point of the outerPolygon and the first point of the hole are connected.
            List<IntPoint> singleStrokePath = new List<IntPoint>();

            singleStrokePath.AddRange(outerPath);
            singleStrokePath.AddRange(holePath);

            return singleStrokePath.Select(ip => new Point((int)ip.X, (int)ip.Y)).ToArray();
        }

        /// <summary>
        /// 閉じたパスを生成
        /// </summary>
        /// <param name="subjectPolygon"></param>
        /// <param name="holePolygons"></param>
        /// <returns></returns>
        public static Point[] MakeHolesInPolygon(Point[] subjectPolygon, List<Point[]> holePolygons)
        {
            Clipper c = new Clipper();
            c.AddPath(subjectPolygon.Select(p => new IntPoint(p.X, p.Y)).ToList(), PolyType.ptSubject, true);

            foreach (var holePolygon in holePolygons)
            {
                c.AddPath(holePolygon.Select(p => new IntPoint(p.X, p.Y)).ToList(), PolyType.ptClip, true);
            }

            List<List<IntPoint>> solution = new List<List<IntPoint>>();
            c.Execute(ClipType.ctDifference, solution,
                PolyFillType.pftNonZero,
                PolyFillType.pftNonZero);

            // Assuming only one polygon with one or more holes
            List<IntPoint> outerEdges = solution[0];

            for (int i = 1; i < solution.Count; i++)
            {
                List<IntPoint> holeEdges = solution[i];

                // Find the closest points between outer edges and hole
                IntPoint closestOuterEdgePoint = outerEdges[0];
                IntPoint closestHoleEdgePoint = holeEdges[0];
                double closestDistance = GetDistance(closestOuterEdgePoint, closestHoleEdgePoint);

                foreach (var outerPoint in outerEdges)
                {
                    foreach (var holePoint in holeEdges)
                    {
                        double distance = GetDistance(outerPoint, holePoint);
                        if (distance < closestDistance)
                        {
                            closestOuterEdgePoint = outerPoint;
                            closestHoleEdgePoint = holePoint;
                            closestDistance = distance;
                        }
                    }
                }

                // Connect outer edge with the hole
                outerEdges.Add(closestHoleEdgePoint);
                outerEdges.AddRange(holeEdges);
                outerEdges.Add(closestOuterEdgePoint); // back to the outer edge
            }

            return outerEdges.Select(ip => new Point((int)ip.X, (int)ip.Y)).ToArray();
        }

        private static double GetDistance(IntPoint p1, IntPoint p2)
        {
            double dx = p1.X - p2.X;
            double dy = p1.Y - p2.Y;
            return Math.Sqrt(dx * dx + dy * dy);
        }
    }
}
