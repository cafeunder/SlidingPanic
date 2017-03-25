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
	public class MainForm : Form {
		private class BoardWithInfo {
			public Board board;
			public int timelimit;
			public Point startPoint;
			public Point goalPoint;

			public BoardWithInfo(Board board, int timelimit, Point startPoint, Point goalPoint) {
				this.board = board;
				this.timelimit = timelimit;
				this.startPoint = startPoint;
				this.goalPoint = goalPoint;
			}
		}

		private List<BoardWithInfo> history = new List<BoardWithInfo>(0);
		private int historyIndex = 0;
		private MenuStrip menuStrip;
		private ToolStripMenuItem fileMenuItem;
		private ToolStripMenuItem saveAsMenuItem;
		private DrawPanel drawPanel;
		private ToolStripMenuItem saveMenuItem;
		private SaveFileDialog sfd;
		private ToolStripMenuItem openMenuItem;
		private ToolStripMenuItem newMenuItem;
		private ToolStripMenuItem 編集ToolStripMenuItem;
		private ToolStripMenuItem backMenuItem;
		private ToolStripMenuItem nextMenuItem;
		private StageInfoForm stageInfoForm;

		public MainForm() {
			this.InitializeComponent();

			this.drawPanel = new DrawPanel();
			this.Controls.Add(this.drawPanel);
			this.ClientSize = new Size(this.drawPanel.Width, this.drawPanel.Height + this.menuStrip.Height);
			this.drawPanel.Top = this.menuStrip.Height;

			this.sfd = new SaveFileDialog();
			this.sfd.FileName = "";
			this.sfd.InitialDirectory = @"..\..\..\project\data\stage";
			this.sfd.Filter = "txtファイル(*.txt)|*.txt|すべてのファイル(*.*)|*.*";
			this.sfd.FilterIndex = 1;
			this.sfd.RestoreDirectory = true;

			this.stageInfoForm = new StageInfoForm(this);
			this.stageInfoForm.Show(this);
		}

		private void InitializeComponent() {
			this.menuStrip = new System.Windows.Forms.MenuStrip();
			this.fileMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.newMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.openMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.saveMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.saveAsMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.編集ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.backMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.nextMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.menuStrip.SuspendLayout();
			this.SuspendLayout();
			// 
			// menuStrip
			// 
			this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileMenuItem,
            this.編集ToolStripMenuItem});
			this.menuStrip.Location = new System.Drawing.Point(0, 0);
			this.menuStrip.Name = "menuStrip";
			this.menuStrip.Size = new System.Drawing.Size(284, 25);
			this.menuStrip.TabIndex = 0;
			this.menuStrip.Text = "menuStrip1";
			// 
			// fileMenuItem
			// 
			this.fileMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newMenuItem,
            this.openMenuItem,
            this.saveMenuItem,
            this.saveAsMenuItem});
			this.fileMenuItem.Name = "fileMenuItem";
			this.fileMenuItem.Size = new System.Drawing.Size(57, 21);
			this.fileMenuItem.Text = "ファイル";
			// 
			// newMenuItem
			// 
			this.newMenuItem.Name = "newMenuItem";
			this.newMenuItem.Size = new System.Drawing.Size(172, 22);
			this.newMenuItem.Text = "新規作成";
			this.newMenuItem.Click += new System.EventHandler(this.NewMenuItem_Click);
			// 
			// openMenuItem
			// 
			this.openMenuItem.Name = "openMenuItem";
			this.openMenuItem.Size = new System.Drawing.Size(172, 22);
			this.openMenuItem.Text = "開く";
			this.openMenuItem.Click += new System.EventHandler(this.OpenMenuItem_Click);
			// 
			// saveMenuItem
			// 
			this.saveMenuItem.Name = "saveMenuItem";
			this.saveMenuItem.Size = new System.Drawing.Size(172, 22);
			this.saveMenuItem.Text = "上書き保存";
			this.saveMenuItem.Click += new System.EventHandler(this.SaveMenuItem_Click);
			// 
			// saveAsMenuItem
			// 
			this.saveAsMenuItem.Name = "saveAsMenuItem";
			this.saveAsMenuItem.Size = new System.Drawing.Size(172, 22);
			this.saveAsMenuItem.Text = "名前を付けて保存";
			this.saveAsMenuItem.Click += new System.EventHandler(this.SaveAsMenuItem_Click);
			// 
			// 編集ToolStripMenuItem
			// 
			this.編集ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.backMenuItem,
            this.nextMenuItem});
			this.編集ToolStripMenuItem.Name = "編集ToolStripMenuItem";
			this.編集ToolStripMenuItem.Size = new System.Drawing.Size(46, 21);
			this.編集ToolStripMenuItem.Text = "編集";
			// 
			// backMenuItem
			// 
			this.backMenuItem.Enabled = false;
			this.backMenuItem.Name = "backMenuItem";
			this.backMenuItem.Size = new System.Drawing.Size(152, 22);
			this.backMenuItem.Text = "元に戻す";
			this.backMenuItem.Click += new System.EventHandler(this.backMenuItem_Click);
			// 
			// nextMenuItem
			// 
			this.nextMenuItem.Enabled = false;
			this.nextMenuItem.Name = "nextMenuItem";
			this.nextMenuItem.Size = new System.Drawing.Size(152, 22);
			this.nextMenuItem.Text = "やり直し";
			this.nextMenuItem.Click += new System.EventHandler(this.nextMenuItem_Click);
			// 
			// MainForm
			// 
			this.ClientSize = new System.Drawing.Size(284, 258);
			this.Controls.Add(this.menuStrip);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MainMenuStrip = this.menuStrip;
			this.MaximizeBox = false;
			this.Name = "MainForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "ステージエディタ";
			this.menuStrip.ResumeLayout(false);
			this.menuStrip.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		private void SaveMenuItem_Click(object sender, EventArgs e) {
			if (this.sfd.FileName == "") {
				this.SaveAsMenuItem_Click(sender, e);
			} else {
				StreamWriter sw = new StreamWriter(this.sfd.FileName);
				this.stageInfoForm.SaveAs(sw);
				this.drawPanel.SaveAs(sw);
				sw.Close();
			}
		}

		private void SaveAsMenuItem_Click(object sender, EventArgs e) {
			this.sfd.Title = "ステージファイルを保存";
			this.sfd.OverwritePrompt = true;
			if (this.sfd.ShowDialog() == DialogResult.OK) {
				StreamWriter sw = new StreamWriter(this.sfd.FileName);
				this.stageInfoForm.SaveAs(sw);
				this.drawPanel.SaveAs(sw);
				sw.Close();
			}
		}

		public void UpdateStageInfo() {
			this.drawPanel.startPoint = this.stageInfoForm.GetStartPoint();
			this.drawPanel.goalPoint = this.stageInfoForm.GetGoalPoint();
			this.drawPanel.Invalidate();
		}

		private void OpenMenuItem_Click(object sender, EventArgs e) {
			this.sfd.Title = "ステージファイルを開く";
			this.sfd.OverwritePrompt = false;
			if (this.sfd.ShowDialog() == DialogResult.OK) {
				StreamReader sr = new StreamReader(this.sfd.FileName);
				this.stageInfoForm.LoadAs(sr);
				this.drawPanel.LoadAs(sr);
				this.history.Clear();
				this.historyIndex = 0;
				sr.Close();
			}
		}

		private void NewMenuItem_Click(object sender, EventArgs e) {
			this.stageInfoForm.Clear();
			this.drawPanel.Clear();
			this.history.Clear();
			this.historyIndex = 0;
		}

		public void UpdateHandler() {
			BoardWithInfo bwi = new BoardWithInfo(
				this.drawPanel.board.Clone(),
				this.stageInfoForm.GetTimelimit(),
				this.stageInfoForm.GetStartPoint(),
				this.stageInfoForm.GetGoalPoint()
			);
			if (this.historyIndex + 1 < this.history.Count) {
				this.history.RemoveRange(this.historyIndex + 1, this.history.Count - this.historyIndex);
			}
			this.history.Add(bwi);
			this.historyIndex++;

			if (this.historyIndex > 0) {
				this.backMenuItem.Enabled = true;
			}
			this.nextMenuItem.Enabled = false;
		}

		private void backMenuItem_Click(object sender, EventArgs e) {
			if (this.historyIndex > 0) {
				this.historyIndex--;
				this.SyncBoardWithInfo();
			}
			if (this.historyIndex <= 0) {
				this.backMenuItem.Enabled = false;
			}
			if (this.historyIndex > 0) {
				this.nextMenuItem.Enabled = true;
			}
		}

		private void nextMenuItem_Click(object sender, EventArgs e) {
			if (this.historyIndex < this.history.Count - 1) {
				this.historyIndex++;
				this.SyncBoardWithInfo();
			}
			if (this.historyIndex >= this.history.Count - 1) {
				this.nextMenuItem.Enabled = false;
			}
			if (this.historyIndex < this.history.Count - 1) {
				this.backMenuItem.Enabled = true;
			}
		}

		public void SyncBoardWithInfo() {
			BoardWithInfo bwi = this.history[this.historyIndex];
			this.drawPanel.board = bwi.board;
			this.stageInfoForm.SetTimelimit(bwi.timelimit);
			this.stageInfoForm.SetStartPoint(bwi.startPoint);
			this.stageInfoForm.SetGoalPoint(bwi.goalPoint);
		}
	}
}
