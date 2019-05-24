using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProyectoArduinoSensores
{
    public partial class Form1 : Form
    {
        string cadena = "";
        public Form1()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            serialPort1.PortName = "COM4";
            lblPWM.Text = trackBar1.Value.ToString();
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            cadena = serialPort1.ReadLine();

            if (cadena.Substring(0, 2) == "S1")
            {
                //lblActivo1.Visible = true;
                textBox1.Text= cadena.Substring(2, cadena.Length-2)+"";

            }
            else if (cadena.Substring(0, 2) == "S2")
            {
                textBox2.Text = cadena.Substring(2, cadena.Length - 2)+ "";
            }
            else if (cadena.Substring(0, 2) == "S3")
            {
                textBox3.Text = cadena.Substring(2, cadena.Length - 2)+ "";
            }
            else if (cadena.Substring(0, 2) == "S5")
            {
                textBox5.Text = cadena.Substring(2, cadena.Length - 2);
            }
            else if (cadena.Substring(0, 3) == "S4A")
            {
                textBox4.Text = cadena.Substring(3, cadena.Length - 3);
            }
            else if (cadena.Substring(0, 3) == "S4B")
            {
                textBox6.Text = cadena.Substring(3, cadena.Length - 3);
            }
        }

        bool activado = true;
        private void button1_Click(object sender, EventArgs e)
        {

            if (!activado) {
                button1.Text = "ACTIVADO";
                this.button1.BackColor = Color.FromArgb(77, 255, 22);
                
                serialPort1.Open();
                activado = true;
            }
            else {
                button1.Text = "DESACTIVADO";
                this.button1.BackColor = Color.FromArgb(255, 27, 22);
                serialPort1.Close();
                activado = false;
                    }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            serialPort1.Close();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            try
            {
                if (Int32.Parse(textBox1.Text) < 200)
                {
                    trackBar1.Value = Int32.Parse(textBox1.Text);
                }

                if (Int32.Parse(textBox1.Text) < 20)
                {
                    label6.Text = "MUY CERCA";
                }

                if (Int32.Parse(textBox1.Text) > 20)
                {
                    label6.Text = "CERCA";
                }

                if (Int32.Parse(textBox1.Text) > 100 && Int32.Parse(textBox1.Text) > 200)
                {
                    label7.Text = "MUY LEJOS";
                }

                if (Int32.Parse(textBox1.Text) > 20 && Int32.Parse(textBox1.Text) < 100)
                {
                    label7.Text = "LEJOS";
                }
            }
            catch
            {

            }

        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {

        }
    }
}
