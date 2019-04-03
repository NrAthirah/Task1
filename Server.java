import java.net.*;
import java.io.*;

public class server
{
	public static void main(String[] args) throws IOException
	{
		ServerSocket serverSocket = new ServerSocket(10000);
		Socket clientSocket = serverSocket.accept();
		
		System.out.println("client connected");
		
		InputStreamReader a = new InputStreamReader(clientSocket.getInputStream());
		
		BufferedReader c = new BufferedReader(a);
		
		PrintWriter q = new PrintWriter(clientSocket.getOutputStream());
		q.println("Ni hao ma");
		q.flush();
		
		String recvr = c.readLine();
		System.out.println(recvr);
	}
}	
