using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing;
using System.IO;

namespace StageMaker {
	class DrawPanel : Panel {
		public const int MERGIN = 10;
		public const int PIECE_SIZE = 48;

		private Board board;
		private Bitmap image;

		public DrawPanel() {
			this.Width = PIECE_SIZE * Board.PIECE_XNUM + MERGIN * 2;
			this.Height = PIECE_SIZE * Board.PIECE_YNUM + MERGIN * 2;

			this.board = new Board();
			this.Paint += this.PaintHandler;
			this.MouseDown += this.ClickHandler;
			this.DoubleBuffered = true;

			this.image = new Bitmap(@"..\..\..\project\data/image/tile.png");
		}

		private void PaintHandler(object sender, PaintEventArgs e) {
			Graphics g = e.Graphics;
			Pen p = new Pen(Color.White, 1);
			Brush b = new SolidBrush(Color.FromArgb(255, 0, 0));
			Brush backgroundBrush = new SolidBrush(Color.FromArgb(0, 0, 0));

			g.FillRectangle(backgroundBrush, 0, 0, this.Width, this.Height);

			int x_num = this.Width / PIECE_SIZE;
			int y_num = this.Height / PIECE_SIZE;

			for (int y = 0; y < y_num; y++) {
				for (int x = 0; x < x_num; x++) {
					int piece_id = this.board.pieceArray[y][x];
					int clip_x = piece_id % 10;	// 画像はタテヨコ 10x10
					int clip_y = piece_id / 10;

					Rectangle draw_area = new Rectangle(MERGIN + x * PIECE_SIZE, MERGIN + y * PIECE_SIZE, PIECE_SIZE, PIECE_SIZE);
					Rectangle clip_area = new Rectangle(clip_x * PIECE_SIZE, clip_y * PIECE_SIZE, PIECE_SIZE, PIECE_SIZE);
					g.DrawRectangle(p, draw_area);
					g.DrawImage(this.image, draw_area, clip_area, GraphicsUnit.Pixel);
				}
			}
		}

		public void ClickHandler(object sender, MouseEventArgs e) {
			Point p = this.PanelPointToBoardPoint(e.X, e.Y);
			if (p.X == -1) { return; }

			if (e.Button == System.Windows.Forms.MouseButtons.Left) {
				this.board.pieceArray[p.Y][p.X]++;
			}
			if (e.Button == System.Windows.Forms.MouseButtons.Right) {
				this.board.pieceArray[p.Y][p.X]--;
			}

			this.Invalidate();
		}

		public Point PanelPointToBoardPoint(int px, int py) {
			if (px < MERGIN || px >= MERGIN + PIECE_SIZE * Board.PIECE_XNUM ||
				py < MERGIN || py >= MERGIN + PIECE_SIZE * Board.PIECE_YNUM) {
				return new Point(-1, -1);
			}

			return new Point((px - MERGIN) / PIECE_SIZE, (py - MERGIN) / PIECE_SIZE);
		}

		public void SaveAs(String filename) {
			StreamWriter sw = new StreamWriter(filename);
			sw.Write("test");
			sw.Close();
		}
	}
}
