using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GlobalConsumable : MonoBehaviour
{
    public static int RandomConsumableNumber;

    public static int Consumable2Count;
    public static int Consumable5Count;
    public static int Consumable10Count;

    public static bool consumableActive = false;
    public static float consumableSecond = 0;

    public GameObject ConsumableRemainingDisplay;
    public GameObject Consumable2Display;
    public GameObject Consumable5Display;
    public GameObject Consumable10Display;

    public int InternalConsumable2;
    public int InternalConsumable5;
    public int InternalConsumable10;

    void Update()
    {
        InternalConsumable2 = Consumable2Count;
        InternalConsumable5 = Consumable5Count;
        InternalConsumable10 = Consumable10Count;

        //Starts with space for formatting
        ConsumableRemainingDisplay.GetComponent<Text>().text = "Consumable Sekuntia Jäljellä: " + consumableSecond.ToString("0.0"); ;
        Consumable2Display.GetComponent<Text>().text = " Consumable2: " + Consumable2Count;
        Consumable5Display.GetComponent<Text>().text = " Consumable5: " + Consumable5Count;
        Consumable10Display.GetComponent<Text>().text = " Consumable10: " + Consumable10Count;
    }

    public static void GiveRandomConsumable (int temp)
    {
        RandomConsumableNumber = temp;

        if (RandomConsumableNumber >= 1 && RandomConsumableNumber <= 3)
        {
            Consumable2Count += 1;
        }
        else if (RandomConsumableNumber >= 4 && RandomConsumableNumber <= 6)
        {
            Consumable5Count += 1;
        }
        else if (RandomConsumableNumber >= 7 && RandomConsumableNumber <= 9)
        {
            Consumable10Count += 1;
        }
    }
}
