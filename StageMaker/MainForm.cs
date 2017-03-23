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
		private MenuStrip menuStrip;
		private ToolStripMenuItem fileMenuItem;
		private ToolStripMenuItem saveAsMenuItem;
		private DrawPanel drawPanel;
		private ToolStripMenuItem saveMenuItem;
		private SaveFileDialog sfd;
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
			this.sfd.Title = "ステージファイルを保存";
			this.sfd.RestoreDirectory = true;

			this.stageInfoForm = new StageInfoForm(this);
			this.stageInfoForm.Show(this);
		}

		private void InitializeComponent() {
			this.menuStrip = new System.Windows.Forms.MenuStrip();
			this.fileMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.saveMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.saveAsMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.menuStrip.SuspendLayout();
			this.SuspendLayout();
			// 
			// menuStrip
			// 
			this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileMenuItem});
			this.menuStrip.Location = new System.Drawing.Point(0, 0);
			this.menuStrip.Name = "menuStrip";
			this.menuStrip.Size = new System.Drawing.Size(284, 25);
			this.menuStrip.TabIndex = 0;
			this.menuStrip.Text = "menuStrip1";
			// 
			// fileMenuItem
			// 
			this.fileMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.saveMenuItem,
            this.saveAsMenuItem});
			this.fileMenuItem.Name = "fileMenuItem";
			this.fileMenuItem.Size = new System.Drawing.Size(57, 21);
			this.fileMenuItem.Text = "ファイル";
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
	}
}
