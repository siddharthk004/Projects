import java.net.*;
import java.io.*;

class server 
{
    public static void main(String arg[]) throws Exception
    {
        System.out.println("server application is running...");
        ServerSocket ssobj = new ServerSocket(2100);
        System.out.println("server is running at port no : 2100");

        Socket s = ssobj.accept();
        System.out.println("server and client connection is successful");

        PrintStream ps = new PrintStream(s.getOutputStream());

        BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));
        
        BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));
        String str1,Str2;
        while((str1 = br1.readLine())!=null)
        {
            System.out.println("client says: "+str1);
            System.out.println("enter message for client : ");
            Str2 = br2.readLine();
            ps.println(Str2);
        }
        System.out.println("thanl you for using chat messanger");
        
    }
}