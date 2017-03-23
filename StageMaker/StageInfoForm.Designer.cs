namespace StageMaker {
	partial class StageInfoForm {
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing) {
			if (disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent() {
			this.label1 = new System.Windows.Forms.Label();
			this.startXUpDown = new System.Windows.Forms.NumericUpDown();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.startYUpDown = new System.Windows.Forms.NumericUpDown();
			this.label4 = new System.Windows.Forms.Label();
			this.goalYUpDown = new System.Windows.Forms.NumericUpDown();
			this.label5 = new System.Windows.Forms.Label();
			this.goalXUpDown = new System.Windows.Forms.NumericUpDown();
			this.label6 = new System.Windows.Forms.Label();
			this.timelimitUpDown = new System.Windows.Forms.NumericUpDown();
			this.label9 = new System.Windows.Forms.Label();
			this.label7 = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.startXUpDown)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.startYUpDown)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.goalYUpDown)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.goalXUpDown)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.timelimitUpDown)).BeginInit();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(12, 44);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(64, 12);
			this.label1.TabIndex = 0;
			this.label1.Text = "スタート地点";
			// 
			// startXUpDown
			// 
			this.startXUpDown.Location = new System.Drawing.Point(99, 42);
			this.startXUpDown.Name = "startXUpDown";
			this.startXUpDown.Size = new System.Drawing.Size(35, 19);
			this.startXUpDown.TabIndex = 1;
			this.startXUpDown.ValueChanged += new System.EventHandler(this.ValueChanged);
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(82, 44);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(12, 12);
			this.label2.TabIndex = 2;
			this.label2.Text = "X";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(145, 44);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(12, 12);
			this.label3.TabIndex = 4;
			this.label3.Text = "Y";
			// 
			// startYUpDown
			// 
			this.startYUpDown.Location = new System.Drawing.Point(162, 42);
			this.startYUpDown.Name = "startYUpDown";
			this.startYUpDown.Size = new System.Drawing.Size(35, 19);
			this.startYUpDown.TabIndex = 3;
			this.startYUpDown.ValueChanged += new System.EventHandler(this.ValueChanged);
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(145, 69);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(12, 12);
			this.label4.TabIndex = 9;
			this.label4.Text = "Y";
			// 
			// goalYUpDown
			// 
			this.goalYUpDown.Location = new System.Drawing.Point(162, 67);
			this.goalYUpDown.Name = "goalYUpDown";
			this.goalYUpDown.Size = new System.Drawing.Size(35, 19);
			this.goalYUpDown.TabIndex = 8;
			this.goalYUpDown.ValueChanged += new System.EventHandler(this.ValueChanged);
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(82, 69);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(12, 12);
			this.label5.TabIndex = 7;
			this.label5.Text = "X";
			// 
			// goalXUpDown
			// 
			this.goalXUpDown.Location = new System.Drawing.Point(99, 67);
			this.goalXUpDown.Name = "goalXUpDown";
			this.goalXUpDown.Size = new System.Drawing.Size(35, 19);
			this.goalXUpDown.TabIndex = 6;
			this.goalXUpDown.ValueChanged += new System.EventHandler(this.ValueChanged);
			// 
			// label6
			// 
			this.label6.AutoSize = true;
			this.label6.Location = new System.Drawing.Point(12, 69);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(58, 12);
			this.label6.TabIndex = 5;
			this.label6.Text = "ゴール地点";
			// 
			// timelimitUpDown
			// 
			this.timelimitUpDown.Location = new System.Drawing.Point(83, 16);
			this.timelimitUpDown.Name = "timelimitUpDown";
			this.timelimitUpDown.Size = new System.Drawing.Size(40, 19);
			this.timelimitUpDown.TabIndex = 11;
			this.timelimitUpDown.Value = new decimal(new int[] {
            30,
            0,
            0,
            0});
			this.timelimitUpDown.ValueChanged += new System.EventHandler(this.ValueChanged);
			// 
			// label9
			// 
			this.label9.AutoSize = true;
			this.label9.Location = new System.Drawing.Point(12, 18);
			this.label9.Name = "label9";
			this.label9.Size = new System.Drawing.Size(53, 12);
			this.label9.TabIndex = 10;
			this.label9.Text = "制限時間";
			// 
			// label7
			// 
			this.label7.AutoSize = true;
			this.label7.Location = new System.Drawing.Point(126, 18);
			this.label7.Name = "label7";
			this.label7.Size = new System.Drawing.Size(25, 12);
			this.label7.TabIndex = 12;
			this.label7.Text = "sec.";
			// 
			// StageInfoForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(212, 100);
			this.Controls.Add(this.label7);
			this.Controls.Add(this.timelimitUpDown);
			this.Controls.Add(this.label9);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.goalYUpDown);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.goalXUpDown);
			this.Controls.Add(this.label6);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.startYUpDown);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.startXUpDown);
			this.Controls.Add(this.label1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "StageInfoForm";
			this.ShowInTaskbar = false;
			this.Text = "StageInfoForm";
			this.Load += new System.EventHandler(this.StageInfoForm_Load);
			((System.ComponentModel.ISupportInitialize)(this.startXUpDown)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.startYUpDown)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.goalYUpDown)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.goalXUpDown)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.timelimitUpDown)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.NumericUpDown startXUpDown;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.NumericUpDown startYUpDown;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.NumericUpDown goalYUpDown;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.NumericUpDown goalXUpDown;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.NumericUpDown timelimitUpDown;
		private System.Windows.Forms.Label label9;
		private System.Windows.Forms.Label label7;
	}
}