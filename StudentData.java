import java.util.*;

class StudentData
{
    public static void main(String arg[])
    {
        DBMS obj = new DBMS();
        obj.StartDBMS();
        
        /*
        obj.InsertIntoTable("Amit",23,89);
        obj.InsertIntoTable("sagar",22,80);
        obj.InsertIntoTable("pooja",21,67);
        obj.InsertIntoTable("sumit",22,77);
        obj.InsertIntoTable("sayali",25,90);

        obj.SelectFrom();
        obj.SelectFrom(4);
        obj.SelectFrom("sayali");

        System.out.println("Maximum marks are : "+obj.Aggregate_MAX());
        System.out.println("Maximum marks are : "+obj.Aggregate_MAX1());
        System.out.println("Minimum marks are : "+obj.Aggregate_MIN());
        System.out.println("Minimum marks are : "+obj.Aggregate_MIN1());
        System.out.println("sum of marks are : "+obj.Aggregate_SUM());
        System.out.println("Avearge of marks are : "+obj.Aggregate_AVG());

        obj.DeleteFrom(3);
        obj.SelectFrom(); 
        */
    }
}

// structure of student
class Student
{
    public int Rno;
    public String Name;
    public int Age;
    public int Marks;
    
    public static int Generator = 0;

    static
    {
        Generator = 0;
    }

    public Student(String str,int X,int Y)
    {
        this.Rno = ++Generator;
        this.Name = str;
        this.Age = X;
        this.Marks = Y;        
    }

    public void display()
    {
        System.out.println(this.Rno+" "+this.Name+" "+this.Age+" "+this.Marks);
    }
}

class DBMS
{
    public LinkedList <Student> lobj;

    public DBMS()
    {
        lobj = new LinkedList <Student> ();
    } 

    public void StartDBMS()
    {
        System.out.println("Marvellous DBMS Started successfully..");
        System.out.println("Table schema created successfully..");
        
        String Query;
        String Token[];
        int Tokenscount = 0;
        Scanner sobj = new Scanner(System.in);
        while(true)
        {
            System.out.println("Siddharth DBMS : ");
            Query = sobj.nextLine();
            Token = Query.split(" ");
            Tokenscount = Token.length;

            if(Tokenscount == 1)
            {
                if("exit".equals(Token[0]))
                {
                    System.out.println("Thank you for using Siddharth DBMS ...");
                    break;
                }
            }
            else if(Tokenscount == 2)
            {}
            else if(Tokenscount == 3)
            {}
            else if(Tokenscount == 4)
            {
                if("select".equals(Token[0]))
                {
                    SelectFrom();
                }
            }
            else if(Tokenscount == 5)
            {
                if("select".equals(Token[0]))
                {
                    if("MAX".equals(Token[1]))
                    {
                        System.out.println("Maximum marks are : "+Aggregate_MAX());
                    }
                    else if("MIN".equals(Token[1]))
                    {
                        System.out.println("minimum marks are : "+Aggregate_MIN());
                    }
                    if("SUM".equals(Token[1]))
                    {
                        System.out.println("summation of marks are : "+Aggregate_SUM());
                    }
                    if("AVG".equals(Token[1]))
                    {
                        System.out.println("Average marks are : "+Aggregate_AVG());
                    }
                }
            }
            else if(Tokenscount == 6)
            {}
            else if(Tokenscount == 7)
            {
                if("insert".equals(Token[0]))
                {
                    InsertIntoTable(Token[4],Integer.parseInt(Token[5]),Integer.parseInt(Token[6]));
                }
                else if("delete".equals(Token[0]))
                {
                    DeleteFrom(Integer.parseInt(Token[6]));
                }
            }
        }
    }   

    public void InsertIntoTable(String Name,int age,int Marks)
    {
        Student sobj = new Student(Name,age,Marks);
        lobj.add(sobj);
    }

    public void SelectFrom()
    {
        System.out.println("Record from the student Table are : ");
        
        for(Student dref : lobj)
        {
            dref.display();            
        }
    }

    // select * from Student where rollnumber = " 4 " 
    public void SelectFrom(int no)
    {
        System.out.println("Record from the student Table are : ");

        for(Student sref : lobj)
        {
            if(sref.Rno == no)
            {
                sref.display();
                break;
            }
        }
    }

    // select * from Student where name = " sayali "
    public void SelectFrom(String str)
    {
        for(Student sref : lobj)
        {
            if(str.equals(sref.Name))
            {
                sref.display();
                break;
            }
        }
    }   
    
    // select MAX(marks) from student
    public int Aggregate_MAX()
    {
        int max = 0;
        for(Student sref : lobj)
        {
            if(sref.Marks > max)
            {
                max = sref.Marks;
            }
        }
        return max;
    } 

    // select MAX(marks) from student
    public int Aggregate_MAX1()
    {   
        Student temp = lobj.get(0);
        int max = temp.Marks;
        for(Student sref : lobj)
        {
            if(sref.Marks > max)
            {
                max = sref.Marks;
            }
        }
        return max;
    } 
        
    // select Min(marks) from student
    public int Aggregate_MIN()
    {
        int min = 999;
        for(Student sref : lobj)
        {
            if(sref.Marks < min)
            {
                min = sref.Marks;
            }
        }
        return min;
    } 

    // select Min(marks) from student
    public int Aggregate_MIN1()
    {
        Student temp = lobj.get(0);
        int min = temp.Marks;     

        for(Student sref : lobj)
        {
            if(sref.Marks < min)
            {
                min = sref.Marks;
            }
        }
        return min;
    } 

    // select sum(marks) from student
    public int Aggregate_SUM()
    {
        Student temp = lobj.get(0);
        int sum = temp.Marks;     

        for(Student sref : lobj)
        {
            sum = sum + sref.Marks;
        }
        return sum;
    }  

    // select avg(marks) from student
    public double Aggregate_AVG()
    {
        Student temp = lobj.get(0);
        int size = lobj.size();
        double avg = 0.0;     

        for(Student sref : lobj)
        {
            avg = avg + sref.Marks;
        }
        return (avg/size);
    }  

    // delete from student where Rno = 2
    public void DeleteFrom(int no)
    {
        int i = 0;
        for(Student sref : lobj)
        {
            if(sref.Rno == no)
            {
                lobj.remove(i);
                break;
            }
            i++;
        }
    }
}
