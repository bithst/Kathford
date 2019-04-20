package Lab1;

import java.io.FileInputStream;
import java.io.InputStream;

// FileInputStreamDemo
public class FileIO {
    public static void main(String[] args) throws Exception {
        int size;
        InputStream file = new FileInputStream("C:\\Academic\\Kathcode\\7th Semester\\[JAVA] Advanced Java Programming\\LabAlt\\src\\Lab1\\FileIO.java");

        System.out.println("Total available bytes: " + (size = file.available()));

        int n = size/40;
        for(int i = 0; i < n; i++) {
            System.out.print((char)file.read());
//            file.skip(size/2);
//            byte b[] = new byte[n];
        }
    }
}
