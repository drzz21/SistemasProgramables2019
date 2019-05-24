using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PWMArduino
{
    public partial class Form1 : Form
    {
        System.IO.Ports.SerialPort ArduinoPort;
       
        byte[] data = new byte[1];

        public Form1()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;
        }

        private void trackPWM_Scroll(object sender, EventArgs e)
        {
            try
            {
                byte pwm;
                pwm = Convert.ToByte(trackPWM.Value);
                data[0] = pwm;
                ArduinoPort.Write(data, 0, 1);
                lblPWMValue.Text = Convert.ToString(pwm);

            }
            catch
            {
                MessageBox.Show("Ha ocurrido un error");
            }



        }

        private void Form1_Load(object sender, EventArgs e)
        {
            lblPWMValue.Text = trackPWM.Value.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                ArduinoPort = new System.IO.Ports.SerialPort();
                ArduinoPort.PortName = textCOM.Text;  //sustituir por vuestro 
                ArduinoPort.BaudRate = 9600;
                ArduinoPort.Open();
                MessageBox.Show("Puerto abierto");
            }
            catch
            {
                MessageBox.Show("Ha ocurrido un error");
            }
            
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (ArduinoPort.IsOpen) ArduinoPort.Close();
        }
    }
}
