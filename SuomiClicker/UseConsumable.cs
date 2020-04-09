using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UseConsumable : MonoBehaviour
{
    public int counter = 1;

    void Update()
    {
        if (GlobalConsumable.consumableSecond > 0)
        {
            for (int i = 0; counter > i; counter--)
            {
                StartCoroutine(UseConsumableSecond());
            }
        }
        else
        {
            counter = 1;
            GlobalConsumable.consumableSecond = 0;
            GlobalMoney.MoneyMultiplierBoost = 0;
            GlobalConsumable.consumableActive = false;
        }
    }

    public void UseConsumable2Button()
    {
        if (GlobalConsumable.Consumable2Count == 0 || GlobalConsumable.consumableActive == true)
        {

        }
        else
        {
            GlobalConsumable.consumableActive = true;
            GlobalConsumable.Consumable2Count -= 1;
            GlobalMoney.MoneyMultiplierBoost = 2;
            GlobalConsumable.consumableSecond = 60;
        }
    }

    public void UseConsumable5Button()
    {
        if (GlobalConsumable.Consumable5Count == 0 || GlobalConsumable.consumableActive == true)
        {

        }
        else
        {
            GlobalConsumable.consumableActive = true;
            GlobalConsumable.Consumable5Count -= 1;
            GlobalMoney.MoneyMultiplierBoost = 5;
            GlobalConsumable.consumableSecond = 60;
        }
    }

    public void UseConsumable10Button()
    {
        if (GlobalConsumable.Consumable10Count == 0 || GlobalConsumable.consumableActive == true)
        {

        }
        else
        {
            GlobalConsumable.consumableActive = true;
            GlobalConsumable.Consumable10Count -= 1;
            GlobalMoney.MoneyMultiplierBoost = 10;
            GlobalConsumable.consumableSecond = 60;
        }
    }

    IEnumerator UseConsumableSecond()
    {
        yield return new WaitForSeconds(0.1F);
        GlobalConsumable.consumableSecond -= 0.1F;
        counter = 1;
    }
}
