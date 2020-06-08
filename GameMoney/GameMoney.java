import java.math.BigInteger;
import java.util.ArrayList;

/**
 * Money class that automatically converts extremely big values in a way that's easier to comprehend for the user.
 * Every value >1000 is converted to a new value + a money letter that cycles through the modern English alphabet (26 letters, a-z).
 * Ex. 1000 = 1a, 1000a = 1b, 1000b = 1c . . . 1000z = 1aa, 1000aa = 1ab, 1000ab = 1ac . . . 1000zz = 1aaa, 1000aaa = 1aab, 1000aab = 1aac . . .
 *
 * You can use and customize this code freely in your commercial or non-commercial projects.
 *
 * Inspired by Penguin Isle: https://play.google.com/store/apps/details?id=com.fantome.penguinisle&hl=en
 *
 * @author @silsanteri
 */
public class Money {
    private BigInteger moneyTotal; // BigInteger for the total money amount.

    private ArrayList<Character> alphabet; // Alphabet Character ArrayList.
    private boolean alphabetType; // Alphabet type. True = Uppercase, False = Lowercase.
    private ArrayList<Integer> letterIndex; // Stores the alphabet index for every letter in an Integer ArrayList.

    // The finalized money amount.
    // moneyFinal Format: 999.99aa where a's are the money letters.
    // The number is a double <1000 rounded to 2 decimal.
    private String moneyFinal;

    /**
     * Constructs the initial values.
     *
     * @param moneyInitial BigInteger - Initial money amount.
     * @param alphabetType_ Boolean - Alphabet type. True = Uppercase, False = Lowercase.
     */
    public Money(BigInteger moneyInitial, boolean alphabetType_){
        this.alphabetType = alphabetType_; // Initiates the alphabetType boolean.
        this.alphabet = this.getAlphabet(alphabetType); // Initiates the alphabet ArrayList.
        this.moneyTotal = new BigInteger("0"); // Initiates the moneyTotal BigInteger.
        this.letterIndex = new ArrayList<>(); // Initiates the letterIndex ArrayList.
        this.letterIndex.add(0); // Sets the first letter index to a default value (0).
        this.addMoney(moneyInitial); // Updates the total money amount to the initial amount.
    }

    /**
     * Constructs the default initial values with no parameters.
     */
    public Money(){
        this.alphabetType = false; // Initiates the alphabetType boolean to false.
        this.alphabet = this.getAlphabet(alphabetType); // Initiates the alphabet ArrayList.
        this.moneyTotal = new BigInteger("0");; // Initiates the moneyTotal BigInteger.
        this.letterIndex = new ArrayList<>(); // Initiates the letterIndex ArrayList.
        this.letterIndex.add(0); // Sets the first letter index to a default value (0).
    }

    /**
     * Returns the finalized money amount.
     *
     * @return String - Finalized money amount.
     */
    public String returnMoney(){

        // Returns the finalized money amount.
        return this.moneyFinal;
    }

    /**
     * Adds the parameter value to the total money amount and updates the final money amount.
     *
     * @param amount BigInteger - Amount of money to add.
     */
    public void addMoney(BigInteger amount){

        // Adds the parameter value to the total money amount.
        this.moneyTotal = this.moneyTotal.add(amount);

        // Updates the final money amount.
        this.updateMoneyFinal();
    }

    /**
     * Removes the parameter value from the total money amount (if enough) and updates the final money amount.
     *
     * @param amount BigInteger - Amount of money to remove.
     */
    public void removeMoney(BigInteger amount){

        // If the total money amount is the same or bigger than the parameter value.
        if(this.moneyTotal.compareTo(amount) == 1 || this.moneyTotal.compareTo(amount) == 0) {

            // Removes the parameter value from the total money amount.
            this.moneyTotal = this.moneyTotal.subtract(amount);

            // Updates the final money amount.
            this.updateMoneyFinal();
        }
    }

    /**
     * Updates the moneyFinal variable.
     **/
    private void updateMoneyFinal(){

        // Creates a temporary BigInteger with the total money amount.
        BigInteger tempMoney = this.moneyTotal;

        // Initializes a temporary finalized money amount.
        double tempFinal = 0;

        // Clears the letter index and sets the first index value to the default (0).
        this.letterIndex.clear();
        this.letterIndex.add(0);

        // While the total temp money amount is >1000.
        while(tempMoney.compareTo(BigInteger.valueOf(1000)) == 1 || tempMoney.compareTo(BigInteger.valueOf(1000)) == 0) {

            // Divides the tempMoney by 1000 and stores the final value in the temporary double.
            tempFinal = tempMoney.doubleValue() / BigInteger.valueOf(1000).doubleValue();
            tempMoney = tempMoney.divide(BigInteger.valueOf(1000));

            // Adds one to the first letter index.
            this.letterIndex.set(0, this.letterIndex.get(0) + 1);
        }

        // Creates the final money String.
        this.moneyFinal = String.format("%.2f", tempFinal) + this.getMoneyLetters();
    }

    /**
     * Returns the finalized money letters.
     *
     * @return String - Returns the finalized money letters.
     */
    private String getMoneyLetters(){

        // Initializes the return String.
        String moneyLetters = "";

        if(this.letterIndex.get(0) == 0){ // If the letterIndex(0) is 0.

            // Returns an empty String.
            return moneyLetters;

        } else { // If letterIndex[0] is not 0.

            // For loop to go through the letterIndex array.
            for(int index = 0; this.letterIndex.size() > index; index++){

                // Calculates the letterIndex[index] value to be within the scope of the alphabet size.
                if(this.letterIndex.get(index) > this.alphabet.size()){

                    // If letterIndex is bigger than the alphabet size, remove the size of the alphabet from it and add +1 to the next array index slot.
                    this.letterIndex.set(index, this.letterIndex.get(index) - this.alphabet.size());

                    // Checks if the new array index slot exists already.
                    int indexCheck = index + 1;
                    if(indexCheck >= this.letterIndex.size()){ // If it does not exist, initiates it as 1.
                        this.letterIndex.add(1);
                    } else { // If it exists, adds +1 to it.
                        this.letterIndex.set(indexCheck, this.letterIndex.get(indexCheck) + 1);
                    }
                }
            }

            // For loop through the letters from the last index to the first.
            for(int index = this.letterIndex.size() - 1; index >= 0; index--){
                // Gets the letter from the alphabet ArrayList to the return String.
                moneyLetters += Character.toString(this.alphabet.get(this.letterIndex.get(index) - 1));
            }

            // Returns the money letters.
            return moneyLetters;
        }
    }

    /**
     * Switches the alphabet capitalization.
     */
    public void switchAlphabet(){

        // Clears the old alphabet ArrayList.
        this.alphabet.clear();

        // Switches the alphabetType to the opposite value.
        if(this.alphabetType){
            this.alphabetType = false;
        } else {
            this.alphabetType = true;
        }

        // Updates the alphabet ArrayList with the new alphabetType parameter.
        this.alphabet = getAlphabet(this.alphabetType);

        // Updates the final money amount to refresh the letter capitalization.
        this.updateMoneyFinal();
    }

    /**
     * Returns the alphabet as a Arraylist<Character>.
     * Capitalization can be toggled with the alphabetType parameter.
     * NOTE: This should always be called in the constructor.
     *
     * @param alphabetType boolean - True = Uppercase, False = Lowercase.
     * @return ArrayList<Character> - Returns the alphabet.
     */
    private ArrayList<Character> getAlphabet(boolean alphabetType) {

        // Creates a temporary alphabet ArrayList.
        ArrayList<Character> tempAlphabet = new ArrayList<>();

        if(alphabetType) { // If alphabetType is True (Uppercase).

            // Uppercase alphabet char array.
            char[] uppercase = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

            // For loop through the uppercase alphabet array and add the values to the alphabet ArrayList.
            for(char c : uppercase){
                tempAlphabet.add(c);
            }

            // Returns the finalized temporary alphabet ArrayList.
            return tempAlphabet;

        } else { // If alphabetType is False (Lowercase).

            // Lowercase alphabet char array.
            char[] lowercase = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

            // For loop through the lowercase alphabet array and add the values to the alphabet ArrayList.
            for(char c : lowercase){
                tempAlphabet.add(c);
            }

            // Returns the finalized temporary alphabet ArrayList.
            return tempAlphabet;
        }
    }
}