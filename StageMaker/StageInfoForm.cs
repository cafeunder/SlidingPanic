using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace StageMaker {
	public partial class StageInfoForm : Form {
		private MainForm mainForm;

		public StageInfoForm(MainForm mainForm) {
			InitializeComponent();
			this.startXUpDown.Maximum = Board.PIECE_XNUM - 1;
			this.goalXUpDown.Maximum = Board.PIECE_XNUM - 1;
			this.startYUpDown.Maximum = Board.PIECE_YNUM - 1;
			this.goalYUpDown.Maximum = Board.PIECE_YNUM - 1;
			this.mainForm = mainForm;
		}

		private void StageInfoForm_Load(object sender, EventArgs e) {
			this.Location = new Point(
				this.Owner.Location.X + this.Owner.Width,
				this.Owner.Location.Y);

			this.goalXUpDown.Value = Board.PIECE_XNUM - 1;
			this.goalYUpDown.Value = Board.PIECE_YNUM - 1;
			this.mainForm.UpdateStageInfo();
		}

		public Point GetStartPoint() {
			return new Point((int)this.startXUpDown.Value, (int)this.startYUpDown.Value);
		}

		public Point GetGoalPoint() {
			return new Point((int)this.goalXUpDown.Value, (int)this.goalYUpDown.Value);
		}

		private void ValueChanged(object sender, EventArgs e) {
			this.mainForm.UpdateStageInfo();
		}

		public void SaveAs(StreamWriter sw) {
			sw.WriteLine(this.timelimitUpDown.Value);
			sw.WriteLine(this.startXUpDown.Value + "," + this.startYUpDown.Value);
			sw.WriteLine(this.goalXUpDown.Value + "," + this.goalYUpDown.Value);
		}
	}
}
