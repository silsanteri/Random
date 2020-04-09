using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PurchaseLogUpgrade : MonoBehaviour
{
   public void BuyUpgrade1()
    {
        GlobalUpgrade.turnOffButton1 = true;
        GlobalMoney.MoneyCount -= GlobalUpgrade.upgrade1Value;
        GlobalUpgrade.upgrade1Multiplier += 1;
        GlobalUpgrade.upgrade1Level += 1;
    }

    public void BuyUpgradeDouble()
    {
        GlobalUpgrade.turnOffButtonDouble = true;
        GlobalMoney.MoneyCount -= GlobalUpgrade.upgradeDoubleValue;
        GlobalUpgrade.upgradeDoubleMultiplier = 2;
        GlobalUpgrade.upgradeDoubleLevel = 1;
    }

    public void BuyUpgradeDoubleInv()
    {
        GlobalUpgrade.turnOffButtonDoubleInv = true;
        GlobalMoney.MoneyCount -= GlobalUpgrade.upgradeDoubleInvValue;
        GlobalUpgrade.upgradeDoubleInvMultiplier = 2;
        GlobalUpgrade.upgradeDoubleInvLevel = 1;
    }

    public void BuyUpgradeCrit()
    {
        GlobalUpgrade.turnOffButtonCrit = true;
        GlobalMoney.MoneyCount -= GlobalUpgrade.upgradeCritValue;
        GlobalUpgrade.upgradeCritValue += 1000;
        GlobalUpgrade.upgradeCritLevel += 1;
    }

    public void BuyUpgradeCrit10()
    {
        GlobalUpgrade.turnOffButtonCrit10 = true;
        GlobalMoney.MoneyCount -= GlobalUpgrade.upgradeCrit10Value;
        GlobalUpgrade.upgradeCrit10Value += 1000;
        GlobalUpgrade.upgradeCrit10Level += 1;
    }

    public void BuyUpgradeConsumableCrit()
    {
        GlobalUpgrade.turnOffButtonConsumableCrit = true;
        GlobalMoney.MoneyCount -= GlobalUpgrade.upgradeConsumableCritValue;
        GlobalUpgrade.upgradeConsumableCritValue += 10000;
        GlobalUpgrade.upgradeConsumableCritLevel += 1;
    }
}