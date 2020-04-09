using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PurchaseLogInvestment : MonoBehaviour
{
    public void BuyInvestmentSauna ()
    {
        if (GlobalMoney.MoneyCount >= GlobalInvestment.investmentSaunaValue)
        {
            GlobalInvestment.turnOffButtonSauna = true;
            GlobalMoney.MoneyCount -= GlobalInvestment.investmentSaunaValue;
            GlobalInvestment.investmentSaunaProfit += 10;
            GlobalInvestment.investmentSaunaLevel += 1;
        }
    }

    public void BuyInvestmentMökki()
    {
        if (GlobalMoney.MoneyCount >= GlobalInvestment.investmentMökkiValue)
        {
            GlobalInvestment.turnOffButtonMökki = true;
            GlobalMoney.MoneyCount -= GlobalInvestment.investmentMökkiValue;
            GlobalInvestment.investmentMökkiProfit += 25;
            GlobalInvestment.investmentMökkiLevel += 1;
        }
    }

    public void BuyInvestmentAsunto()
    {
        if (GlobalMoney.MoneyCount >= GlobalInvestment.investmentAsuntoValue)
        {
            GlobalInvestment.turnOffButtonAsunto = true;
            GlobalMoney.MoneyCount -= GlobalInvestment.investmentAsuntoValue;
            GlobalInvestment.investmentAsuntoProfit += 50;
            GlobalInvestment.investmentAsuntoLevel += 1;
        }
    }

    public void BuyInvestmentMegaShopper()
    {
        if (GlobalMoney.MoneyCount >= GlobalInvestment.investmentMegaShopperValue)
        {
            GlobalInvestment.turnOffButtonMegaShopper = true;
            GlobalMoney.MoneyCount -= GlobalInvestment.investmentMegaShopperValue;
            GlobalInvestment.investmentMegaShopperProfit += 100;
            GlobalInvestment.investmentMegaShopperLevel += 1;
        }
    }

    public void BuyInvestmentOtso()
    {
        if (GlobalMoney.MoneyCount >= GlobalInvestment.investmentOtsoValue)
        {
            GlobalInvestment.turnOffButtonOtso = true;
            GlobalMoney.MoneyCount -= GlobalInvestment.investmentOtsoValue;
            GlobalInvestment.investmentOtsoProfit += 250;
            GlobalInvestment.investmentOtsoLevel += 1;
        }
    }

    public void BuyInvestmentSuomimaa()
    {
        if (GlobalMoney.MoneyCount >= GlobalInvestment.investmentSuomimaaValue)
        {
            GlobalInvestment.turnOffButtonSuomimaa = true;
            GlobalMoney.MoneyCount -= GlobalInvestment.investmentSuomimaaValue;
            GlobalInvestment.investmentSuomimaaProfit += 500;
            GlobalInvestment.investmentSuomimaaLevel += 1;
        }
    }

    public void BuyInvestmentKasino()
    {
        if (GlobalMoney.MoneyCount >= GlobalInvestment.investmentKasinoValue)
        {
            GlobalInvestment.turnOffButtonKasino = true;
            GlobalMoney.MoneyCount -= GlobalInvestment.investmentKasinoValue;
            GlobalInvestment.investmentKasinoProfit += 1000;
            GlobalInvestment.investmentKasinoLevel += 1;
        }
    }

    public void BuyInvestmentTori()
    {
        if (GlobalMoney.MoneyCount >= GlobalInvestment.investmentToriValue)
        {
            GlobalInvestment.turnOffButtonTori = true;
            GlobalMoney.MoneyCount -= GlobalInvestment.investmentToriValue;
            GlobalInvestment.investmentToriProfit += 10000;
            GlobalInvestment.investmentToriLevel += 1;
        }
    }

    public void BuyInvestmentJääkiekko()
    {
        if (GlobalMoney.MoneyCount >= GlobalInvestment.investmentJääkiekkoValue)
        {
            GlobalInvestment.turnOffButtonJääkiekko = true;
            GlobalMoney.MoneyCount -= GlobalInvestment.investmentJääkiekkoValue;
            GlobalInvestment.investmentJääkiekkoProfit += 100000;
            GlobalInvestment.investmentJääkiekkoLevel += 1;
        }
    }
}
