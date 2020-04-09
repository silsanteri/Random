using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GlobalUpgrade: MonoBehaviour
{
    public int currentMoney;

    public static int upgradeCritRandom;
    public static int upgradeCrit10Random;
    public static int upgradeConsumableCritRandom;

    //UPGRADE 1
    public GameObject realButton1;
    public GameObject realText1;
    public GameObject realStats1;
    public GameObject fakeButton1;
    public GameObject fakeText1;
    public GameObject fakeStats1;

    public static int upgrade1Multiplier = 1;
    public static int upgrade1Value = 1000;
    public static int upgrade1Level = 0;
    public static bool turnOffButton1 = false;

    //UPGRADE DOUBLE
    public GameObject realButtonDouble;
    public GameObject realTextDouble;
    public GameObject realStatsDouble;
    public GameObject fakeButtonDouble;
    public GameObject fakeTextDouble;
    public GameObject fakeStatsDouble;

    public static int upgradeDoubleMultiplier = 1;
    public static int upgradeDoubleValue = 10000;
    public static int upgradeDoubleLevel = 0;
    public static bool turnOffButtonDouble = false;

    //UPGRADE DOUBLEINV
    public GameObject realButtonDoubleInv;
    public GameObject realTextDoubleInv;
    public GameObject realStatsDoubleInv;
    public GameObject fakeButtonDoubleInv;
    public GameObject fakeTextDoubleInv;
    public GameObject fakeStatsDoubleInv;

    public static int upgradeDoubleInvMultiplier = 1;
    public static int upgradeDoubleInvValue = 10000;
    public static int upgradeDoubleInvLevel = 0;
    public static bool turnOffButtonDoubleInv = false;

    //UPGRADE CRIT
    public GameObject realButtonCrit;
    public GameObject realTextCrit;
    public GameObject realStatsCrit;
    public GameObject fakeButtonCrit;
    public GameObject fakeTextCrit;
    public GameObject fakeStatsCrit;


    public static int upgradeCritValue = 1000;
    public static int upgradeCritLevel = 0;
    public static bool turnOffButtonCrit = false;

    //UPGRADE CRIT10
    public GameObject realButtonCrit10;
    public GameObject realTextCrit10;
    public GameObject realStatsCrit10;
    public GameObject fakeButtonCrit10;
    public GameObject fakeTextCrit10;
    public GameObject fakeStatsCrit10;


    public static int upgradeCrit10Value = 1000;
    public static int upgradeCrit10Level = 0;
    public static bool turnOffButtonCrit10 = false;

    //UPGRADE CONSUMABLECRIT
    public GameObject realButtonConsumableCrit;
    public GameObject realTextConsumableCrit;
    public GameObject realStatsConsumableCrit;
    public GameObject fakeButtonConsumableCrit;
    public GameObject fakeTextConsumableCrit;
    public GameObject fakeStatsConsumableCrit;


    public static int upgradeConsumableCritValue = 10000;
    public static int upgradeConsumableCritLevel = 0;
    public static bool turnOffButtonConsumableCrit = false;

    void Update()
    {
        currentMoney = GlobalMoney.MoneyCount;

        //UPGRADE 1
        fakeStats1.GetComponent<Text>().text = "Taso: " + upgrade1Level + "/100";
        realStats1.GetComponent<Text>().text = "Taso: " + upgrade1Level + "/100";
        fakeText1.GetComponent<Text>().text = "Osta parannus: " + upgrade1Value + " Markkaa";
        realText1.GetComponent<Text>().text = "Osta parannus: " + upgrade1Value + " Markkaa";

        if (currentMoney >= upgrade1Value && upgrade1Level < 100)
        {
            fakeButton1.SetActive(false);
            realButton1.SetActive(true);
        }

        if (turnOffButton1 == true)
        {
            realButton1.SetActive(false);
            fakeButton1.SetActive(true);
            turnOffButton1 = false;
        }

        //UPGRADE DOUBLE
        fakeStatsDouble.GetComponent<Text>().text = "Ostettu: " + upgradeDoubleLevel;
        realStatsDouble.GetComponent<Text>().text = "Ostettu: " + upgradeDoubleLevel;
        fakeTextDouble.GetComponent<Text>().text = "Osta parannus: " + upgradeDoubleValue + " Markkaa";
        realTextDouble.GetComponent<Text>().text = "Osta parannus: " + upgradeDoubleValue + " Markkaa";

        if (currentMoney >= upgradeDoubleValue && upgradeDoubleLevel == 0)
        {
            fakeButtonDouble.SetActive(false);
            realButtonDouble.SetActive(true);
        }

        if (turnOffButtonDouble == true)
        {
            realButtonDouble.SetActive(false);
            fakeButtonDouble.SetActive(true);
            turnOffButtonDouble = false;
        }

        //UPGRADE DOUBLEINV
        fakeStatsDoubleInv.GetComponent<Text>().text = "Ostettu: " + upgradeDoubleInvLevel;
        realStatsDoubleInv.GetComponent<Text>().text = "Ostettu: " + upgradeDoubleInvLevel;
        fakeTextDoubleInv.GetComponent<Text>().text = "Osta parannus: " + upgradeDoubleInvValue + " Markkaa";
        realTextDoubleInv.GetComponent<Text>().text = "Osta parannus: " + upgradeDoubleInvValue + " Markkaa";

        if (currentMoney >= upgradeDoubleInvValue && upgradeDoubleInvLevel == 0)
        {
            fakeButtonDoubleInv.SetActive(false);
            realButtonDoubleInv.SetActive(true);
        }

        if (turnOffButtonDoubleInv == true)
        {
            realButtonDoubleInv.SetActive(false);
            fakeButtonDoubleInv.SetActive(true);
            turnOffButtonDoubleInv = false;
        }

        //UPGRADE CRIT
        fakeStatsCrit.GetComponent<Text>().text = "Taso: " + upgradeCritLevel + "/10";
        realStatsCrit.GetComponent<Text>().text = "Taso: " + upgradeCritLevel + "/10";
        fakeTextCrit.GetComponent<Text>().text = "Osta parannus: " + upgradeCritValue + " Markkaa";
        realTextCrit.GetComponent<Text>().text = "Osta parannus: " + upgradeCritValue + " Markkaa";

        if (currentMoney >= upgradeCritValue && upgradeCritLevel < 10)
        {
            fakeButtonCrit.SetActive(false);
            realButtonCrit.SetActive(true);
        }

        if (turnOffButtonCrit == true)
        {
            realButtonCrit.SetActive(false);
            fakeButtonCrit.SetActive(true);
            turnOffButtonCrit = false;
        }

        //UPGRADE CRIT10
        fakeStatsCrit10.GetComponent<Text>().text = "Taso: " + upgradeCrit10Level + "/10";
        realStatsCrit10.GetComponent<Text>().text = "Taso: " + upgradeCrit10Level + "/10";
        fakeTextCrit10.GetComponent<Text>().text = "Osta parannus: " + upgradeCrit10Value + " Markkaa";
        realTextCrit10.GetComponent<Text>().text = "Osta parannus: " + upgradeCrit10Value + " Markkaa";

        if (currentMoney >= upgradeCrit10Value && upgradeCrit10Level < 10)
        {
            fakeButtonCrit10.SetActive(false);
            realButtonCrit10.SetActive(true);
        }

        if (turnOffButtonCrit10 == true)
        {
            realButtonCrit10.SetActive(false);
            fakeButtonCrit10.SetActive(true);
            turnOffButtonCrit10 = false;
        }

        //UPGRADE CONSUMABLECRIT
        fakeStatsConsumableCrit.GetComponent<Text>().text = "Taso: " + upgradeConsumableCritLevel + "/10";
        realStatsConsumableCrit.GetComponent<Text>().text = "Taso: " + upgradeConsumableCritLevel + "/10";
        fakeTextConsumableCrit.GetComponent<Text>().text = "Osta parannus: " + upgradeConsumableCritValue + " Markkaa";
        realTextConsumableCrit.GetComponent<Text>().text = "Osta parannus: " + upgradeConsumableCritValue + " Markkaa";

        if (currentMoney >= upgradeConsumableCritValue && upgradeConsumableCritLevel < 10)
        {
            fakeButtonConsumableCrit.SetActive(false);
            realButtonConsumableCrit.SetActive(true);
        }

        if (turnOffButtonConsumableCrit == true)
        {
            realButtonConsumableCrit.SetActive(false);
            fakeButtonConsumableCrit.SetActive(true);
            turnOffButtonConsumableCrit = false;
        }
    }

    //RANDOM NUMBER GENERATORS MADE WITH EVERY MAINBUTTONCLICK
    public static void UpgradeCritRandomGenerator(int temp)
    {
        upgradeCritRandom = temp;
    }

    public static void UpgradeCrit10RandomGenerator(int temp)
    {
        upgradeCrit10Random = temp;
    }

    public static void UpgradeConsumableCritRandomGenerator(int temp)
    {
        upgradeConsumableCritRandom = temp;
    }
}
