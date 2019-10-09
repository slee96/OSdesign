import java.net.*;
import java.io.*;

public class EchoServer extends Thread {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(8080);

        while (true){
            Socket socket = null;
            try{
                socket = serverSocket.accept();
                BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter output = new PrintWriter(socket.getOutputStream(), true);

            }catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

    public void run() {
        //BufferedReader reader;
        //PrintWriter output;
        try {
            // server infinite loop
            //while (true) {
                //Socket socket = serverSocket.accept();
                //reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                //output = new PrintWriter(socket.getOutputStream(), true);

                // Response/Echo infinite loop
                while (true) {
                    output.println("Server: " + reader.readLine());
                }
            //}
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}