using System;
using System.Collections.Generic;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Client
{
    class RoundButton : Button
    {
        protected override void OnResize(EventArgs e)
        {
            using(var path = new GraphicsPath())
            {
                path.AddEllipse(new System.Drawing.RectangleF(2,2,this.Width-5,this.Height-5));
                this.Region = new System.Drawing.Region(path);
            }
            base.OnResize(e);
        }
    }
}
