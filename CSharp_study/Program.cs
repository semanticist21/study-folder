using System;
using System.Collections.Generic;

namespace CSharp_study
{

    abstract class MyAbstract
    {
        protected void ProtectedMethod()
        {
            Console.WriteLine("");
        }

        public void PublicMethod()
        {
            Console.WriteLine("");
        }

        public abstract void AbstractMethod();
    }
    class Program
    {
        class DemoClass
        {
            private int demoField;
            public int DemoField
            {
                get { return DemoField; }
                set
                {
                    demoField = value;
                }
            }

            static void Main(string[] args)
            {
            }
        }
    }
