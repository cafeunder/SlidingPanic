using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace StageMaker {
	public partial class StageInfoForm : Form {
		public StageInfoForm() {
			InitializeComponent();
		}

		private void StageInfoForm_Load(object sender, EventArgs e) {
			this.Location = new Point(
				this.Owner.Location.X + this.Owner.Width,
				this.Owner.Location.Y + (this.Owner.Height - this.Height) / 2);
		}
	}
}
