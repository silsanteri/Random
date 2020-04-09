using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GlobalMoney : MonoBehaviour
{
    public int InternalMoney;
    public static int MoneyCount;
    public int MoneyCounter = 1;

    public int Consumable2Switch = 1;
    public int Consumable5Switch = 1;
    public int Consumable10Switch = 1;

    public static int MoneyMultiplierBoost = 0;
    public static int MoneyMultiplierUpgrade;
    public static int MoneyPerClick;
    public static int MoneyPerSecond;

    public GameObject MoneyDisplay;
    public GameObject MoneyPerClickDisplay;
    public GameObject MoneyPerSecondDisplay;

    void Update()
    {
        InternalMoney = MoneyCount;

        //MONEY PER SECOND
        MoneyPerSecond = GlobalInvestment.investmentSaunaProfit + GlobalInvestment.investmentMökkiProfit + GlobalInvestment.investmentAsuntoProfit;
        MoneyPerSecond = MoneyPerSecond + GlobalInvestment.investmentMegaShopperProfit + GlobalInvestment.investmentOtsoProfit + GlobalInvestment.investmentSuomimaaProfit;
        MoneyPerSecond = MoneyPerSecond + GlobalInvestment.investmentKasinoProfit + GlobalInvestment.investmentToriProfit + GlobalInvestment.investmentJääkiekkoProfit;
        MoneyPerSecond *= GlobalUpgrade.upgradeDoubleInvMultiplier;
        MoneyPerSecond *= GlobalInvestment.investmentHyvinvointivaltio;
        MoneyPerSecond *= GlobalInvestment.investmentYrittäjä;

        if (MoneyPerSecond >= 1)
        {
            for (int i = 0; MoneyCounter > i; MoneyCounter--)
            {
                StartCoroutine(MoneyPerSecondMaker());
            }
        }
        else
        {
            MoneyCounter = 1;
        }

        //MONEY PER CLICK
        MoneyMultiplierUpgrade = (GlobalUpgrade.upgrade1Multiplier * GlobalUpgrade.upgradeDoubleMultiplier) * GlobalInvestment.investmentHyvinvointivaltio;
        if (MoneyMultiplierBoost == 0)
        {
            MoneyPerClick = MoneyMultiplierUpgrade;
        }
        else
        {
            MoneyPerClick = MoneyMultiplierBoost + MoneyMultiplierUpgrade;
        }

        //MONEY DISPLAY
        MoneyDisplay.GetComponent<Text>().text = "Markka: " + InternalMoney;
        MoneyPerClickDisplay.GetComponent<Text>().text = "Markka Kerroin: " + MoneyPerClick;
        MoneyPerSecondDisplay.GetComponent<Text>().text = "Markkaa Sekunnissa: " + MoneyPerSecond;

        //CONSUMABLE PER SEC
        if (GlobalInvestment.investmentMegaShopperLevel != 0)
        {
            for (int u = 0; Consumable2Switch > u; Consumable2Switch--)
            {
                StartCoroutine(Consumable2Giver());
            }
        }
        else
        {
            Consumable2Switch = 1;
        }

        if (GlobalInvestment.investmentOtsoLevel != 0)
        {
            for (int y = 0; Consumable5Switch > y; Consumable5Switch--)
            {
                StartCoroutine(Consumable5Giver());
            }
        }
        else
        {
            Consumable5Switch = 1;
        }

        if (GlobalInvestment.investmentSuomimaaLevel != 0)
        {
            for (int t = 0; Consumable10Switch > t; Consumable10Switch--)
            {
                StartCoroutine(Consumable10Giver());
            }
        }
        else
        {
            Consumable10Switch = 1;
        }
    }

    IEnumerator MoneyPerSecondMaker()
    {
        yield return new WaitForSeconds(1);
        MoneyCount += MoneyPerSecond;
        MoneyCounter = 1;
    }

    IEnumerator Consumable2Giver()
    {
        yield return new WaitForSeconds(60);
        GlobalConsumable.Consumable2Count++;
        Consumable2Switch = 1;
    }

    IEnumerator Consumable5Giver()
    {
        yield return new WaitForSeconds(60);
        GlobalConsumable.Consumable5Count++;
        Consumable5Switch = 1;
    }

    IEnumerator Consumable10Giver()
    {
        yield return new WaitForSeconds(60);
        GlobalConsumable.Consumable10Count++;
        Consumable10Switch = 1;
    }
}
