using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ManageConsumable : MonoBehaviour
{
    //BUY
    //CONSUMABLE
    public void BuyConsumable2Button()
    {
        if (GlobalMoney.MoneyCount <= 199)
        {

        }
        else
        {
        GlobalMoney.MoneyCount -= 200;
        GlobalConsumable.Consumable2Count += 1;
        }
    }

    public void BuyConsumable5Button()
    {
        if (GlobalMoney.MoneyCount <= 499)
        {

        }
        else
        {
            GlobalMoney.MoneyCount -= 500;
            GlobalConsumable.Consumable5Count += 1;
        }
    }

    public void BuyConsumable10Button()
    {
        if (GlobalMoney.MoneyCount <= 999)
        {

        }
        else
        {
            GlobalMoney.MoneyCount -= 1000;
            GlobalConsumable.Consumable10Count += 1;
        }
    }

    //SELL
    //CONSUMABLE

    public void SellConsumable2Button()
    {
        if (GlobalConsumable.Consumable2Count <= 0)
        {

        }
        else
        {
            GlobalMoney.MoneyCount += 100;
            GlobalConsumable.Consumable2Count -= 1;
        }
    }

    public void SellConsumable5Button()
    {
        if (GlobalConsumable.Consumable5Count <= 0)
        {

        }
        else
        {
            GlobalMoney.MoneyCount += 250;
            GlobalConsumable.Consumable5Count -= 1;
        }
    }

    public void SellConsumable10Button()
    {
        if (GlobalConsumable.Consumable10Count <= 0)
        {

        }
        else
        {
            GlobalMoney.MoneyCount += 500;
            GlobalConsumable.Consumable10Count -= 1;
        }
    }
}
