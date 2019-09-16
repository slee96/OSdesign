// File Name GreetingServer.java
import java.net.*;
import java.io.*;

public class EchoServer extends Thread {
    private ServerSocket serverSocket;

    public EchoServer(int port) throws IOException {
        serverSocket = new ServerSocket(port);
        serverSocket.setSoTimeout(20000);
    }

    public void run() {
        while(true) {
            
        }
    }

    public static void main(String [] args) {
        try {
            Thread t = new EchoServer(8080);
            t.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}