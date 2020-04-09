using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SaveGame : MonoBehaviour
{
    public int savedMoney;
    public int savedConsumable2;
    public int savedConsumable5;
    public int savedConsumable10;

    public int savedUpgrade1Level;
    public int savedUpgrade1Multiplier;
    public int savedUpgradeDoubleLevel;
    public int savedUpgradeDoubleMultiplier;
    public int savedUpgradeDoubleInvLevel;
    public int savedUpgradeDoubleInvMultiplier;
    public int savedUpgradeCritLevel;
    public int savedUpgradeCritValue;
    public int savedUpgradeCrit10Level;
    public int savedUpgradeCrit10Value;
    public int savedUpgradeConsumableCritLevel;
    public int savedUpgradeConsumableCritValue;

    public int savedInvestmentSaunaProfit;
    public int savedInvestmentSaunaValue;
    public int savedInvestmentSaunaLevel;
    public int savedInvestmentMökkiProfit;
    public int savedInvestmentMökkiValue;
    public int savedInvestmentMökkiLevel;
    public int savedInvestmentAsuntoProfit;
    public int savedInvestmentAsuntoValue;
    public int savedInvestmentAsuntoLevel;
    public int savedInvestmentHyvinvointivaltio;

    public int savedInvestmentMegaShopperProfit;
    public int savedInvestmentMegaShopperValue;
    public int savedInvestmentMegaShopperLevel;
    public int savedInvestmentOtsoProfit;
    public int savedInvestmentOtsoValue;
    public int savedInvestmentOtsoLevel;
    public int savedInvestmentSuomimaaProfit;
    public int savedInvestmentSuomimaaValue;
    public int savedInvestmentSuomimaaLevel;
    public int savedInvestmentYrittäjä;

    public int savedInvestmentKasinoProfit;
    public int savedInvestmentKasinoValue;
    public int savedInvestmentKasinoLevel;
    public int savedInvestmentToriProfit;
    public int savedInvestmentToriValue;
    public int savedInvestmentToriLevel;
    public int savedInvestmentJääkiekkoProfit;
    public int savedInvestmentJääkiekkoValue;
    public int savedInvestmentJääkiekkoLevel;

    //LOADGAME
    void Start()
    {
        savedMoney = PlayerPrefs.GetInt("SavedMoney");
        GlobalMoney.MoneyCount = savedMoney;

        savedConsumable2 = PlayerPrefs.GetInt("SavedConsumable2");
        GlobalConsumable.Consumable2Count = savedConsumable2;

        savedConsumable5 = PlayerPrefs.GetInt("SavedConsumable5");
        GlobalConsumable.Consumable5Count = savedConsumable5;

        savedConsumable10 = PlayerPrefs.GetInt("SavedConsumable10");
        GlobalConsumable.Consumable10Count = savedConsumable10;

        savedUpgrade1Level = PlayerPrefs.GetInt("SavedUpgrade1Level");
        GlobalUpgrade.upgrade1Level = savedUpgrade1Level;
        savedUpgrade1Multiplier = PlayerPrefs.GetInt("SavedUpgrade1Multiplier");
        GlobalUpgrade.upgrade1Multiplier = savedUpgrade1Multiplier;

        savedUpgradeDoubleLevel = PlayerPrefs.GetInt("SavedUpgradeDoubleLevel");
        GlobalUpgrade.upgradeDoubleLevel = savedUpgradeDoubleLevel;
        savedUpgradeDoubleMultiplier = PlayerPrefs.GetInt("SavedUpgradeDoubleMultiplier");
        GlobalUpgrade.upgradeDoubleMultiplier = savedUpgradeDoubleMultiplier;

        savedUpgradeDoubleInvLevel = PlayerPrefs.GetInt("SavedUpgradeDoubleInvLevel");
        GlobalUpgrade.upgradeDoubleInvLevel = savedUpgradeDoubleInvLevel;
        savedUpgradeDoubleInvMultiplier = PlayerPrefs.GetInt("SavedUpgradeDoubleInvMultiplier");
        GlobalUpgrade.upgradeDoubleInvMultiplier = savedUpgradeDoubleInvMultiplier;

        savedUpgradeCritLevel = PlayerPrefs.GetInt("SavedUpgradeCritLevel");
        GlobalUpgrade.upgradeCritLevel = savedUpgradeCritLevel;
        savedUpgradeCritValue = PlayerPrefs.GetInt("SavedUpgradeCritValue");
        GlobalUpgrade.upgradeCritValue = savedUpgradeCritValue;

        savedUpgradeCrit10Level = PlayerPrefs.GetInt("SavedUpgradeCrit10Level");
        GlobalUpgrade.upgradeCrit10Level = savedUpgradeCrit10Level;
        savedUpgradeCrit10Value = PlayerPrefs.GetInt("SavedUpgradeCrit10Value");
        GlobalUpgrade.upgradeCrit10Value = savedUpgradeCrit10Value;

        savedUpgradeConsumableCritLevel = PlayerPrefs.GetInt("SavedUpgradeConsumableCritLevel");
        GlobalUpgrade.upgradeConsumableCritLevel = savedUpgradeConsumableCritLevel;
        savedUpgradeConsumableCritValue = PlayerPrefs.GetInt("SavedUpgradeConsumableCritValue");
        GlobalUpgrade.upgradeConsumableCritValue = savedUpgradeConsumableCritValue;

        savedInvestmentSaunaProfit = PlayerPrefs.GetInt("SavedInvestmentSaunaProfit");
        GlobalInvestment.investmentSaunaProfit = savedInvestmentSaunaProfit;
        savedInvestmentSaunaLevel = PlayerPrefs.GetInt("SavedInvestmentSaunaLevel");
        GlobalInvestment.investmentSaunaLevel = savedInvestmentSaunaLevel;
        savedInvestmentSaunaValue = PlayerPrefs.GetInt("SavedInvestmentSaunaValue");
        GlobalInvestment.investmentSaunaValue = savedInvestmentSaunaValue;

        savedInvestmentMökkiProfit = PlayerPrefs.GetInt("SavedInvestmentMökkiProfit");
        GlobalInvestment.investmentMökkiProfit = savedInvestmentMökkiProfit;
        savedInvestmentMökkiLevel = PlayerPrefs.GetInt("SavedInvestmentMökkiLevel");
        GlobalInvestment.investmentMökkiLevel = savedInvestmentMökkiLevel;
        savedInvestmentMökkiValue = PlayerPrefs.GetInt("SavedInvestmentMökkiValue");
        GlobalInvestment.investmentMökkiValue = savedInvestmentMökkiValue;

        savedInvestmentAsuntoProfit = PlayerPrefs.GetInt("SavedInvestmentAsuntoProfit");
        GlobalInvestment.investmentAsuntoProfit = savedInvestmentAsuntoProfit;
        savedInvestmentAsuntoLevel = PlayerPrefs.GetInt("SavedInvestmentAsuntoLevel");
        GlobalInvestment.investmentAsuntoLevel = savedInvestmentAsuntoLevel;
        savedInvestmentAsuntoValue = PlayerPrefs.GetInt("SavedInvestmentAsuntoValue");
        GlobalInvestment.investmentAsuntoValue = savedInvestmentAsuntoValue;

        savedInvestmentHyvinvointivaltio = PlayerPrefs.GetInt("SavedInvestmentHyvinvointivaltio");
        GlobalInvestment.investmentHyvinvointivaltio = savedInvestmentHyvinvointivaltio;

        savedInvestmentMegaShopperProfit = PlayerPrefs.GetInt("SavedInvestmentMegaShopperProfit");
        GlobalInvestment.investmentMegaShopperProfit = savedInvestmentMegaShopperProfit;
        savedInvestmentMegaShopperLevel = PlayerPrefs.GetInt("SavedInvestmentMegaShopperLevel");
        GlobalInvestment.investmentMegaShopperLevel = savedInvestmentMegaShopperLevel;
        savedInvestmentMegaShopperValue = PlayerPrefs.GetInt("SavedInvestmentMegaShopperValue");
        GlobalInvestment.investmentMegaShopperValue = savedInvestmentMegaShopperValue;

        savedInvestmentOtsoProfit = PlayerPrefs.GetInt("SavedInvestmentOtsoProfit");
        GlobalInvestment.investmentOtsoProfit = savedInvestmentOtsoProfit;
        savedInvestmentOtsoLevel = PlayerPrefs.GetInt("SavedInvestmentOtsoLevel");
        GlobalInvestment.investmentOtsoLevel = savedInvestmentOtsoLevel;
        savedInvestmentOtsoValue = PlayerPrefs.GetInt("SavedInvestmentOtsoValue");
        GlobalInvestment.investmentOtsoValue = savedInvestmentOtsoValue;

        savedInvestmentSuomimaaProfit = PlayerPrefs.GetInt("SavedInvestmentSuomimaaProfit");
        GlobalInvestment.investmentSuomimaaProfit = savedInvestmentSuomimaaProfit;
        savedInvestmentSuomimaaLevel = PlayerPrefs.GetInt("SavedInvestmentSuomimaaLevel");
        GlobalInvestment.investmentSuomimaaLevel = savedInvestmentSuomimaaLevel;
        savedInvestmentSuomimaaValue = PlayerPrefs.GetInt("SavedInvestmentSuomimaaValue");
        GlobalInvestment.investmentSuomimaaValue = savedInvestmentSuomimaaValue;

        savedInvestmentYrittäjä = PlayerPrefs.GetInt("SavedInvestmentYrittäjä");
        GlobalInvestment.investmentYrittäjä = savedInvestmentYrittäjä;

        savedInvestmentKasinoProfit = PlayerPrefs.GetInt("SavedInvestmentKasinoProfit");
        GlobalInvestment.investmentKasinoProfit = savedInvestmentKasinoProfit;
        savedInvestmentKasinoLevel = PlayerPrefs.GetInt("SavedInvestmentKasinoLevel");
        GlobalInvestment.investmentKasinoLevel = savedInvestmentKasinoLevel;
        savedInvestmentKasinoValue = PlayerPrefs.GetInt("SavedInvestmentKasinoValue");
        GlobalInvestment.investmentKasinoValue = savedInvestmentKasinoValue;

        savedInvestmentToriProfit = PlayerPrefs.GetInt("SavedInvestmentToriProfit");
        GlobalInvestment.investmentToriProfit = savedInvestmentToriProfit;
        savedInvestmentToriLevel = PlayerPrefs.GetInt("SavedInvestmentToriLevel");
        GlobalInvestment.investmentToriLevel = savedInvestmentToriLevel;
        savedInvestmentToriValue = PlayerPrefs.GetInt("SavedInvestmentToriValue");
        GlobalInvestment.investmentToriValue = savedInvestmentToriValue;

        savedInvestmentJääkiekkoProfit = PlayerPrefs.GetInt("SavedInvestmentJääkiekkoProfit");
        GlobalInvestment.investmentJääkiekkoProfit = savedInvestmentJääkiekkoProfit;
        savedInvestmentJääkiekkoLevel = PlayerPrefs.GetInt("SavedInvestmentJääkiekkoLevel");
        GlobalInvestment.investmentJääkiekkoLevel = savedInvestmentJääkiekkoLevel;
        savedInvestmentJääkiekkoValue = PlayerPrefs.GetInt("SavedInvestmentJääkiekkoValue");
        GlobalInvestment.investmentJääkiekkoValue = savedInvestmentJääkiekkoValue;
    }


    public static void SaveTheGame()
    {
        PlayerPrefs.SetInt("SavedMoney", GlobalMoney.MoneyCount);
        PlayerPrefs.SetInt("SavedConsumable2", GlobalConsumable.Consumable2Count);
        PlayerPrefs.SetInt("SavedConsumable5", GlobalConsumable.Consumable5Count);
        PlayerPrefs.SetInt("SavedConsumable10", GlobalConsumable.Consumable10Count);
        PlayerPrefs.SetInt("SavedUpgrade1Level", GlobalUpgrade.upgrade1Level);
        PlayerPrefs.SetInt("SavedUpgrade1Multiplier", GlobalUpgrade.upgrade1Multiplier);
        PlayerPrefs.SetInt("SavedUpgradeDoubleLevel", GlobalUpgrade.upgradeDoubleLevel);
        PlayerPrefs.SetInt("SavedUpgradeDoubleMultiplier", GlobalUpgrade.upgradeDoubleMultiplier);
        PlayerPrefs.SetInt("SavedUpgradeDoubleInvLevel", GlobalUpgrade.upgradeDoubleInvLevel);
        PlayerPrefs.SetInt("SavedUpgradeDoubleInvMultiplier", GlobalUpgrade.upgradeDoubleInvMultiplier);
        PlayerPrefs.SetInt("SavedUpgradeCritLevel", GlobalUpgrade.upgradeCritLevel);
        PlayerPrefs.SetInt("SavedUpgradeCritValue", GlobalUpgrade.upgradeCritValue);
        PlayerPrefs.SetInt("SavedUpgradeCrit10Level", GlobalUpgrade.upgradeCrit10Level);
        PlayerPrefs.SetInt("SavedUpgradeCrit10Value", GlobalUpgrade.upgradeCrit10Value);
        PlayerPrefs.SetInt("SavedUpgradeConsumableCritLevel", GlobalUpgrade.upgradeConsumableCritLevel);
        PlayerPrefs.SetInt("SavedUpgradeConsumableCritValue", GlobalUpgrade.upgradeConsumableCritValue);
        PlayerPrefs.SetInt("SavedInvestmentSaunaProfit", GlobalInvestment.investmentSaunaProfit);
        PlayerPrefs.SetInt("SavedInvestmentSaunaLevel", GlobalInvestment.investmentSaunaLevel);
        PlayerPrefs.SetInt("SavedInvestmentSaunaValue", GlobalInvestment.investmentSaunaValue);
        PlayerPrefs.SetInt("SavedInvestmentMökkiProfit", GlobalInvestment.investmentMökkiProfit);
        PlayerPrefs.SetInt("SavedInvestmentMökkiLevel", GlobalInvestment.investmentMökkiLevel);
        PlayerPrefs.SetInt("SavedInvestmentMökkiValue", GlobalInvestment.investmentMökkiValue);
        PlayerPrefs.SetInt("SavedInvestmentAsuntoProfit", GlobalInvestment.investmentAsuntoProfit);
        PlayerPrefs.SetInt("SavedInvestmentAsuntoLevel", GlobalInvestment.investmentAsuntoLevel);
        PlayerPrefs.SetInt("SavedInvestmentAsuntoValue", GlobalInvestment.investmentAsuntoValue);
        PlayerPrefs.SetInt("SavedInvestmentHyvinvointivaltio", GlobalInvestment.investmentHyvinvointivaltio);
        PlayerPrefs.SetInt("SavedInvestmentMegaShopperProfit", GlobalInvestment.investmentMegaShopperProfit);
        PlayerPrefs.SetInt("SavedInvestmentMegaShopperLevel", GlobalInvestment.investmentMegaShopperLevel);
        PlayerPrefs.SetInt("SavedInvestmentMegaShopperValue", GlobalInvestment.investmentMegaShopperValue);
        PlayerPrefs.SetInt("SavedInvestmentOtsoProfit", GlobalInvestment.investmentOtsoProfit);
        PlayerPrefs.SetInt("SavedInvestmentOtsoLevel", GlobalInvestment.investmentOtsoLevel);
        PlayerPrefs.SetInt("SavedInvestmentOtsoValue", GlobalInvestment.investmentOtsoValue);
        PlayerPrefs.SetInt("SavedInvestmentSuomimaaProfit", GlobalInvestment.investmentSuomimaaProfit);
        PlayerPrefs.SetInt("SavedInvestmentSuomimaaLevel", GlobalInvestment.investmentSuomimaaLevel);
        PlayerPrefs.SetInt("SavedInvestmentSuomimaaValue", GlobalInvestment.investmentSuomimaaValue);
        PlayerPrefs.SetInt("SavedInvestmentYrittäjä", GlobalInvestment.investmentYrittäjä);
        PlayerPrefs.SetInt("SavedInvestmentKasinoProfit", GlobalInvestment.investmentKasinoProfit);
        PlayerPrefs.SetInt("SavedInvestmentKasinoLevel", GlobalInvestment.investmentKasinoLevel);
        PlayerPrefs.SetInt("SavedInvestmentKasinoValue", GlobalInvestment.investmentKasinoValue);
        PlayerPrefs.SetInt("SavedInvestmentToriProfit", GlobalInvestment.investmentToriProfit);
        PlayerPrefs.SetInt("SavedInvestmentToriLevel", GlobalInvestment.investmentToriLevel);
        PlayerPrefs.SetInt("SavedInvestmentToriValue", GlobalInvestment.investmentToriValue);
        PlayerPrefs.SetInt("SavedInvestmentJääkiekkoProfit", GlobalInvestment.investmentJääkiekkoProfit);
        PlayerPrefs.SetInt("SavedInvestmentJääkiekkoLevel", GlobalInvestment.investmentJääkiekkoLevel);
        PlayerPrefs.SetInt("SavedInvestmentJääkiekkoValue", GlobalInvestment.investmentJääkiekkoValue);
    }


    public static void DeleteSave()
    {
        PlayerPrefs.SetInt("SavedMoney", 0);
        PlayerPrefs.SetInt("SavedConsumable2", 0);
        PlayerPrefs.SetInt("SavedConsumable5", 0);
        PlayerPrefs.SetInt("SavedConsumable10", 0);
        PlayerPrefs.SetInt("SavedUpgrade1Level", 0);
        PlayerPrefs.SetInt("SavedUpgrade1Multiplier", 1);
        PlayerPrefs.SetInt("SavedUpgradeDoubleLevel", 0);
        PlayerPrefs.SetInt("SavedUpgradeDoubleMultiplier", 1);
        PlayerPrefs.SetInt("SavedUpgradeDoubleInvLevel", 0);
        PlayerPrefs.SetInt("SavedUpgradeDoubleInvMultiplier", 1);
        PlayerPrefs.SetInt("SavedUpgradeCritLevel", 0);
        PlayerPrefs.SetInt("SavedUpgradeCritValue", 1000);
        PlayerPrefs.SetInt("SavedUpgradeCrit10Level", 0);
        PlayerPrefs.SetInt("SavedUpgradeCrit10Value", 1000);
        PlayerPrefs.SetInt("SavedUpgradeConsumableCritLevel", 0);
        PlayerPrefs.SetInt("SavedUpgradeConsumableCritValue", 10000);
        PlayerPrefs.SetInt("SavedInvestmentSaunaProfit", 0);
        PlayerPrefs.SetInt("SavedInvestmentSaunaLevel", 0);
        PlayerPrefs.SetInt("SavedInvestmentSaunaValue", 10000);
        PlayerPrefs.SetInt("SavedInvestmentMökkiProfit", 0);
        PlayerPrefs.SetInt("SavedInvestmentMökkiLevel", 0);
        PlayerPrefs.SetInt("SavedInvestmentMökkiValue", 50000);
        PlayerPrefs.SetInt("SavedInvestmentAsuntoProfit", 0);
        PlayerPrefs.SetInt("SavedInvestmentAsuntoLevel", 0);
        PlayerPrefs.SetInt("SavedInvestmentAsuntoValue", 100000);
        PlayerPrefs.SetInt("SavedInvestmentHyvinvointivaltio", 1);
        PlayerPrefs.SetInt("SavedInvestmentMegaShopperProfit", 0);
        PlayerPrefs.SetInt("SavedInvestmentMegaShopperLevel", 0);
        PlayerPrefs.SetInt("SavedInvestmentMegaShopperValue", 100000);
        PlayerPrefs.SetInt("SavedInvestmentOtsoProfit", 0);
        PlayerPrefs.SetInt("SavedInvestmentOtsoLevel", 0);
        PlayerPrefs.SetInt("SavedInvestmentOtsoValue", 500000);
        PlayerPrefs.SetInt("SavedInvestmentSuomimaaProfit", 0);
        PlayerPrefs.SetInt("SavedInvestmentSuomimaaLevel", 0);
        PlayerPrefs.SetInt("SavedInvestmentSuomimaaValue", 1000000);
        PlayerPrefs.SetInt("SavedInvestmentYrittäjä", 1);
        PlayerPrefs.SetInt("SavedInvestmentKasinoProfit", 0);
        PlayerPrefs.SetInt("SavedInvestmentKasinoLevel", 0);
        PlayerPrefs.SetInt("SavedInvestmentKasinoValue", 1000000);
        PlayerPrefs.SetInt("SavedInvestmentToriProfit", 0);
        PlayerPrefs.SetInt("SavedInvestmentToriLevel", 0);
        PlayerPrefs.SetInt("SavedInvestmentToriValue", 10000000);
        PlayerPrefs.SetInt("SavedInvestmentJääkiekkoProfit", 0);
        PlayerPrefs.SetInt("SavedInvestmentJääkiekkoLevel", 0);
        PlayerPrefs.SetInt("SavedInvestmentJääkiekkoValue", 10000000);

        //DELETE TEMP SAVED VALUES WHEN SAVE IS DELETED
        GlobalMoney.MoneyMultiplierBoost = 0;
        GlobalConsumable.consumableSecond = 0;
        GlobalConsumable.consumableActive = false;
    }
}