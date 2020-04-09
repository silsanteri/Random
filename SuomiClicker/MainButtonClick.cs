using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MainButtonClick : MonoBehaviour
{
    public void ClickTheButton()
    {
        GlobalUpgrade.UpgradeConsumableCritRandomGenerator(Random.Range(1, 100));
        GlobalUpgrade.UpgradeCritRandomGenerator(Random.Range(1, 100));
        GlobalUpgrade.UpgradeCrit10RandomGenerator(Random.Range(1, 1000));

        //CRITICAL UPGRADES
        if (GlobalUpgrade.upgradeCrit10Level != 0 && GlobalUpgrade.upgradeCrit10Level >= GlobalUpgrade.upgradeCrit10Random)
        {
            GlobalMoney.MoneyCount += 10 * GlobalMoney.MoneyPerClick;
        }
        else if (GlobalUpgrade.upgradeCritLevel != 0 && GlobalUpgrade.upgradeCritLevel >= GlobalUpgrade.upgradeCritRandom)
        {
            GlobalMoney.MoneyCount += 2 * GlobalMoney.MoneyPerClick;
        }
        else
        {
            GlobalMoney.MoneyCount += GlobalMoney.MoneyPerClick;
        }

        if (GlobalUpgrade.upgradeConsumableCritLevel != 0 && GlobalUpgrade.upgradeConsumableCritLevel >= GlobalUpgrade.upgradeConsumableCritRandom)
        {
            GlobalConsumable.GiveRandomConsumable(Random.Range(1, 9));
        }
    }
}
