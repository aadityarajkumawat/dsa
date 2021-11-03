package programs;

import java.util.Scanner;

public class StackArray {
    public static void main(String[] args) {
        char c = ' ';
        Scanner sc = new Scanner(System.in);
        System.out.println("Stack with aray");
        System.out.println("Enter the size of stack:");
        int n = sc.nextInt();

        Stack s = new Stack(n);

        do {
            System.out.println("Stack Operations");
            System.out.println("1. Push Operation \n" + "2. Pop Operation \n" + "3. Overflow Check \n"
                    + "4. Underflow Check \n" + "5. Peek \n" + "6. Display \n");
            int choice = sc.nextInt();
            switch (choice) {
            case 1:
                System.out.println("Push Operation\ninput a number:");
                int val = sc.nextInt();
                s.push(val);
                break;
            case 2:
                System.out.println("Pop Operation");
                s.pop();
                break;
            case 3:
                System.out.println("Overflow Check: " + s.overflow());
                break;
            case 4:
                System.out.println("Underflow Check: " + s.underflow());
                break;
            case 5:
                System.out.println("Peek: " + s.peek());
                break;
            case 6:
                System.out.println("Display");
                s.display();
                break;
            default:
                System.out.println("invalid input");
            }
            s.display();
            System.out.println("\nDo you want to continue(y/ n)");
            c = sc.next().charAt(0);
        } while (c == 'y' || c == 'Y');

        sc.close();
    }
}
