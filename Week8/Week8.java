import java.util.Random;
import java.util.Scanner;

public class Week8 {
	
	static {
		System.loadLibrary("Week8Library");
	}

	public static void main(String[] args) {
		
		String input;
		int n = -1, min = 0, max = 100;
		int[] numArray = new int[1];
		
		Scanner sc = new Scanner(System.in);
		do {
			System.out.printf("Enter the number of samples to generate: ");
			try {
				n = sc.nextInt();
				System.out.println();
			} catch (NumberFormatException e) {
				System.err.printf("-- Invalid input! Must be integer from '%d' to '%d'.\n", min, max);
				continue;
			}
			
			if (n == 0) {
				System.out.println("-- Zero samples to calculate! Terminating program.");
				System.exit(0);
			} 
			else if (n > min && n <= max) {
				numArray = new int[n];
				break;
			}
			
			System.err.printf("-- Invalid input! Must be integer from '%d' to '%d'.\n", min, max);
		} while (n < min || n > max);		
		
		// For each element in the integer-array.
		for (int i = 0; i < n; i++) {
			numArray[i] = new Random().nextInt(max);
			System.out.printf("%d%s", 
				numArray[i], (i < n-1) ? ", " : ".");
			//if (i < n-1) System.out.print(", ");
		}
		System.out.println("\n");

		
		
		Week8 main = new Week8();
		double stdDev = main.calculateStdDev(numArray);
		double mean = main.calculateMean(numArray);
		
		System.out.println("Std-Dev: " + stdDev + " | Mean: " + mean);
	}
	
	public native double calculateStdDev(int[] numbers);
	
	public native double calculateMean(int[] numbers);
}
