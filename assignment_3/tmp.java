import java.net.*;
import java.io.*;

public class EchoServer {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(8080);

        while (true) {
            Socket socket = null;
            try {
                socket = serverSocket.accept();
                BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter output = new PrintWriter(socket.getOutputStream(), true);

                Thread t = new threadHandler(socket, reader, output);

                t.start();

            } catch (Exception e) {
                socket.close();
                e.printStackTrace();
            }

        }
    }
}

class threadHandler extends Thread{
    private Socket s;
    private BufferedReader in;
    private PrintWriter out;

    public threadHandler(Socket s, BufferedReader in, PrintWriter out){
        this.s = s;
        this.in = in;
        this.out = out;
    }


    public void run() {
        try {
            // Response/Echo infinite loop
            while (true) {
                out.println("Server: " + in.readLine());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

