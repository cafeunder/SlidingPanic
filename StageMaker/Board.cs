using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StageMaker {
	class Board {
		public const int PIECE_XNUM = 12;
		public const int PIECE_YNUM = 8;

		public int[][] pieceArray{ get; set; }

		public Board() {
			this.pieceArray = new int[PIECE_YNUM][];
			for (int y = 0; y < PIECE_YNUM; y++) {
				this.pieceArray[y] = new int[PIECE_XNUM];
				for (int x = 0; x < PIECE_XNUM; x++) {
					this.pieceArray[y][x] = 1;
				}
			}
		}
	}
}
