package Alber;

import java.util.Scanner;

public class Fatoração {

	public static void main (String[] args) {

		Scanner input = new Scanner(System.in);	
		int numero,fatoração;
		
		System.out.println("digite o numero que sera fatorado");
		numero=input.nextInt();
		
		for(fatoração=1;numero>1;numero=numero-1) {
			
			fatoração=numero*fatoração;
			
		}
		
		System.out.println(fatoração);
		
		
	}
}
