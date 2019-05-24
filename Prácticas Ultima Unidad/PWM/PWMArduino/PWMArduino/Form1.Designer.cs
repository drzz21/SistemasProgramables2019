namespace PWMArduino
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.trackPWM = new System.Windows.Forms.TrackBar();
            this.lblPWMValue = new System.Windows.Forms.Label();
            this.textCOM = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.trackPWM)).BeginInit();
            this.SuspendLayout();
            // 
            // trackPWM
            // 
            this.trackPWM.Location = new System.Drawing.Point(43, 103);
            this.trackPWM.Maximum = 255;
            this.trackPWM.Name = "trackPWM";
            this.trackPWM.Size = new System.Drawing.Size(535, 45);
            this.trackPWM.TabIndex = 0;
            this.trackPWM.Value = 50;
            this.trackPWM.Scroll += new System.EventHandler(this.trackPWM_Scroll);
            // 
            // lblPWMValue
            // 
            this.lblPWMValue.AutoSize = true;
            this.lblPWMValue.Font = new System.Drawing.Font("Microsoft Sans Serif", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPWMValue.Location = new System.Drawing.Point(634, 75);
            this.lblPWMValue.Name = "lblPWMValue";
            this.lblPWMValue.Size = new System.Drawing.Size(104, 73);
            this.lblPWMValue.TabIndex = 1;
            this.lblPWMValue.Text = "50";
            // 
            // textCOM
            // 
            this.textCOM.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textCOM.Location = new System.Drawing.Point(60, 19);
            this.textCOM.Name = "textCOM";
            this.textCOM.Size = new System.Drawing.Size(100, 30);
            this.textCOM.TabIndex = 2;
            this.textCOM.Text = "COM4";
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(176, 15);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(178, 39);
            this.button1.TabIndex = 3;
            this.button1.Text = "Asignar puerto";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(783, 251);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textCOM);
            this.Controls.Add(this.lblPWMValue);
            this.Controls.Add(this.trackPWM);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.trackPWM)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TrackBar trackPWM;
        private System.Windows.Forms.Label lblPWMValue;
        private System.Windows.Forms.TextBox textCOM;
        private System.Windows.Forms.Button button1;
    }
}

