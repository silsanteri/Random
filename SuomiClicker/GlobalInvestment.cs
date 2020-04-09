using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GlobalInvestment : MonoBehaviour
{
    public int currentMoney;

    //SAUNA
    public GameObject realButtonSauna;
    public GameObject realTextSauna;
    public GameObject realStatsSauna;
    public GameObject fakeButtonSauna;
    public GameObject fakeTextSauna;
    public GameObject fakeStatsSauna;

    public static int investmentSaunaProfit = 0;
    public static int investmentSaunaValue = 10000;
    public static int investmentSaunaLevel = 0;
    public static bool turnOffButtonSauna = false;

    //MÖKKI
    public GameObject realButtonMökki;
    public GameObject realTextMökki;
    public GameObject realStatsMökki;
    public GameObject fakeButtonMökki;
    public GameObject fakeTextMökki;
    public GameObject fakeStatsMökki;

    public static int investmentMökkiProfit = 0;
    public static int investmentMökkiValue = 50000;
    public static int investmentMökkiLevel = 0;
    public static bool turnOffButtonMökki = false;

    //ASUNTO
    public GameObject realButtonAsunto;
    public GameObject realTextAsunto;
    public GameObject realStatsAsunto;
    public GameObject fakeButtonAsunto;
    public GameObject fakeTextAsunto;
    public GameObject fakeStatsAsunto;

    public static int investmentAsuntoProfit = 0;
    public static int investmentAsuntoValue = 100000;
    public static int investmentAsuntoLevel = 0;
    public static bool turnOffButtonAsunto = false;

    //HYVINVOINTIVALTIO (SAUNA, MÖKKI, ASUNTO)
    public static int investmentHyvinvointivaltio = 1;

    //MEGASHOPPER
    public GameObject realButtonMegaShopper;
    public GameObject realTextMegaShopper;
    public GameObject realStatsMegaShopper;
    public GameObject fakeButtonMegaShopper;
    public GameObject fakeTextMegaShopper;
    public GameObject fakeStatsMegaShopper;

    public static int investmentMegaShopperProfit = 0;
    public static int investmentMegaShopperValue = 100000;
    public static int investmentMegaShopperLevel = 0;
    public static bool turnOffButtonMegaShopper = false;

    //OTSO
    public GameObject realButtonOtso;
    public GameObject realTextOtso;
    public GameObject realStatsOtso;
    public GameObject fakeButtonOtso;
    public GameObject fakeTextOtso;
    public GameObject fakeStatsOtso;

    public static int investmentOtsoProfit = 0;
    public static int investmentOtsoValue = 500000;
    public static int investmentOtsoLevel = 0;
    public static bool turnOffButtonOtso = false;

    //SUOMIMAA
    public GameObject realButtonSuomimaa;
    public GameObject realTextSuomimaa;
    public GameObject realStatsSuomimaa;
    public GameObject fakeButtonSuomimaa;
    public GameObject fakeTextSuomimaa;
    public GameObject fakeStatsSuomimaa;

    public static int investmentSuomimaaProfit = 0;
    public static int investmentSuomimaaValue = 1000000;
    public static int investmentSuomimaaLevel = 0;
    public static bool turnOffButtonSuomimaa = false;

    //YRITTÄJÄ (MEGASHOPPER, OTSO, SUOMIMAA)
    public static int investmentYrittäjä = 1;

    //KASINO
    public GameObject realButtonKasino;
    public GameObject realTextKasino;
    public GameObject realStatsKasino;
    public GameObject fakeButtonKasino;
    public GameObject fakeTextKasino;
    public GameObject fakeStatsKasino;

    public static int investmentKasinoProfit = 0;
    public static int investmentKasinoValue = 1000000;
    public static int investmentKasinoLevel = 0;
    public static bool turnOffButtonKasino = false;

    //TORI
    public GameObject realButtonTori;
    public GameObject realTextTori;
    public GameObject realStatsTori;
    public GameObject fakeButtonTori;
    public GameObject fakeTextTori;
    public GameObject fakeStatsTori;

    public static int investmentToriProfit = 0;
    public static int investmentToriValue = 10000000;
    public static int investmentToriLevel = 0;
    public static bool turnOffButtonTori = false;

    //JÄÄKIEKKO
    public GameObject realButtonJääkiekko;
    public GameObject realTextJääkiekko;
    public GameObject realStatsJääkiekko;
    public GameObject fakeButtonJääkiekko;
    public GameObject fakeTextJääkiekko;
    public GameObject fakeStatsJääkiekko;

    public static int investmentJääkiekkoProfit = 0;
    public static int investmentJääkiekkoValue = 100000000;
    public static int investmentJääkiekkoLevel = 0;
    public static bool turnOffButtonJääkiekko = false;

    void Update()
    {
        currentMoney = GlobalMoney.MoneyCount;

        //SAUNA
        fakeStatsSauna.GetComponent<Text>().text = "Taso: " + investmentSaunaLevel + "/10";
        realStatsSauna.GetComponent<Text>().text = "Taso: " + investmentSaunaLevel + "/10";
        fakeTextSauna.GetComponent<Text>().text = "Osta Sauna: " + investmentSaunaValue + " Markkaa";
        realTextSauna.GetComponent<Text>().text = "Osta Sauna: " + investmentSaunaValue + " Markkaa";

        if (currentMoney >= investmentSaunaValue && investmentSaunaLevel < 10)
        {
            fakeButtonSauna.SetActive(false);
            realButtonSauna.SetActive(true);
        }

        if (turnOffButtonSauna == true)
        {
            fakeButtonSauna.SetActive(true);
            realButtonSauna.SetActive(false);
            turnOffButtonSauna = false;
        }

        //MÖKKI
        fakeStatsMökki.GetComponent<Text>().text = "Taso: " + investmentMökkiLevel + "/10";
        realStatsMökki.GetComponent<Text>().text = "Taso: " + investmentMökkiLevel + "/10";
        fakeTextMökki.GetComponent<Text>().text = "Osta Mökki: " + investmentMökkiValue + " Markkaa";
        realTextMökki.GetComponent<Text>().text = "Osta Mökki: " + investmentMökkiValue + " Markkaa";

        if (currentMoney >= investmentMökkiValue && investmentMökkiLevel < 10)
        {
            fakeButtonMökki.SetActive(false);
            realButtonMökki.SetActive(true);
        }

        if (turnOffButtonMökki == true)
        {
            fakeButtonMökki.SetActive(true);
            realButtonMökki.SetActive(false);
            turnOffButtonMökki = false;
        }

        //ASUNTO
        fakeStatsAsunto.GetComponent<Text>().text = "Taso: " + investmentAsuntoLevel + "/10";
        realStatsAsunto.GetComponent<Text>().text = "Taso: " + investmentAsuntoLevel + "/10";
        fakeTextAsunto.GetComponent<Text>().text = "Osta Asunto: " + investmentAsuntoValue + " Markkaa";
        realTextAsunto.GetComponent<Text>().text = "Osta Asunto: " + investmentAsuntoValue + " Markkaa";

        if (currentMoney >= investmentAsuntoValue && investmentAsuntoLevel < 10)
        {
            fakeButtonAsunto.SetActive(false);
            realButtonAsunto.SetActive(true);
        }

        if (turnOffButtonAsunto == true)
        {
            fakeButtonAsunto.SetActive(true);
            realButtonAsunto.SetActive(false);
            turnOffButtonAsunto = false;
        }

        //HYVINVOINTIVALTIO (SAUNA, MÖKKI, ASUNTO)
        if (investmentSaunaLevel == 10 && investmentMökkiLevel == 10 && investmentAsuntoLevel == 10)
        {
            investmentHyvinvointivaltio = 2;
        }

        //MEGASHOPPER
        fakeStatsMegaShopper.GetComponent<Text>().text = "Taso: " + investmentMegaShopperLevel + "/10";
        realStatsMegaShopper.GetComponent<Text>().text = "Taso: " + investmentMegaShopperLevel + "/10";
        fakeTextMegaShopper.GetComponent<Text>().text = "Osta MegaShopper Tehdas: " + investmentMegaShopperValue + " Markkaa";
        realTextMegaShopper.GetComponent<Text>().text = "Osta MegaShopper Tehdas: " + investmentMegaShopperValue + " Markkaa";

        if (currentMoney >= investmentMegaShopperValue && investmentMegaShopperLevel < 10)
        {
            fakeButtonMegaShopper.SetActive(false);
            realButtonMegaShopper.SetActive(true);
        }

        if (turnOffButtonMegaShopper == true)
        {
            fakeButtonMegaShopper.SetActive(true);
            realButtonMegaShopper.SetActive(false);
            turnOffButtonMegaShopper = false;
        }

        //OTSO
        fakeStatsOtso.GetComponent<Text>().text = "Taso: " + investmentOtsoLevel + "/10";
        realStatsOtso.GetComponent<Text>().text = "Taso: " + investmentOtsoLevel + "/10";
        fakeTextOtso.GetComponent<Text>().text = "Osta Otso Panimo: " + investmentOtsoValue + " Markkaa";
        realTextOtso.GetComponent<Text>().text = "Osta Otso Panimo: " + investmentOtsoValue + " Markkaa";

        if (currentMoney >= investmentOtsoValue && investmentOtsoLevel < 10)
        {
            fakeButtonOtso.SetActive(false);
            realButtonOtso.SetActive(true);
        }

        if (turnOffButtonOtso == true)
        {
            fakeButtonOtso.SetActive(true);
            realButtonOtso.SetActive(false);
            turnOffButtonOtso = false;
        }

        //SUOMIMAA
        fakeStatsSuomimaa.GetComponent<Text>().text = "Taso: " + investmentSuomimaaLevel + "/10";
        realStatsSuomimaa.GetComponent<Text>().text = "Taso: " + investmentSuomimaaLevel + "/10";
        fakeTextSuomimaa.GetComponent<Text>().text = "Osta Suomimaa Tislaamo: " + investmentSuomimaaValue + " Markkaa";
        realTextSuomimaa.GetComponent<Text>().text = "Osta Suomimaa Tislaamo: " + investmentSuomimaaValue + " Markkaa";

        if (currentMoney >= investmentSuomimaaValue && investmentSuomimaaLevel < 10)
        {
            fakeButtonSuomimaa.SetActive(false);
            realButtonSuomimaa.SetActive(true);
        }

        if (turnOffButtonSuomimaa == true)
        {
            fakeButtonSuomimaa.SetActive(true);
            realButtonSuomimaa.SetActive(false);
            turnOffButtonSuomimaa = false;
        }

        //YRITTÄJÄ (MEGASHOPPER, OTSO, SUOMIMAA)
        if (investmentMegaShopperLevel == 10 && investmentOtsoLevel == 10 && investmentSuomimaaLevel == 10)
        {
            investmentYrittäjä = 2;
        }

        //KASINO
        fakeStatsKasino.GetComponent<Text>().text = "Taso: " + investmentKasinoLevel + "/1";
        realStatsKasino.GetComponent<Text>().text = "Taso: " + investmentKasinoLevel + "/1";
        fakeTextKasino.GetComponent<Text>().text = "Osta Kasino: " + investmentKasinoValue + " Markkaa";
        realTextKasino.GetComponent<Text>().text = "Osta Kasino: " + investmentKasinoValue + " Markkaa";

        if (currentMoney >= investmentKasinoValue && investmentKasinoLevel < 1)
        {
            fakeButtonKasino.SetActive(false);
            realButtonKasino.SetActive(true);
        }

        if (turnOffButtonKasino == true)
        {
            fakeButtonKasino.SetActive(true);
            realButtonKasino.SetActive(false);
            turnOffButtonKasino = false;
        }

        //TORI
        fakeStatsTori.GetComponent<Text>().text = "Taso: " + investmentToriLevel + "/1";
        realStatsTori.GetComponent<Text>().text = "Taso: " + investmentToriLevel + "/1";
        fakeTextTori.GetComponent<Text>().text = "Osta Tori: " + investmentToriValue + " Markkaa";
        realTextTori.GetComponent<Text>().text = "Osta Tori: " + investmentToriValue + " Markkaa";

        if (currentMoney >= investmentToriValue && investmentToriLevel < 1)
        {
            fakeButtonTori.SetActive(false);
            realButtonTori.SetActive(true);
        }

        if (turnOffButtonTori == true)
        {
            fakeButtonTori.SetActive(true);
            realButtonTori.SetActive(false);
            turnOffButtonTori = false;
        }

        //JÄÄKIEKKO
        fakeStatsJääkiekko.GetComponent<Text>().text = "Taso: " + investmentJääkiekkoLevel + "/1";
        realStatsJääkiekko.GetComponent<Text>().text = "Taso: " + investmentJääkiekkoLevel + "/1";
        fakeTextJääkiekko.GetComponent<Text>().text = "Osta Jääkiekko Areena: " + investmentJääkiekkoValue + " Markkaa";
        realTextJääkiekko.GetComponent<Text>().text = "Osta Jääkiekko Areena: " + investmentJääkiekkoValue + " Markkaa";

        if (currentMoney >= investmentJääkiekkoValue && investmentJääkiekkoLevel < 10)
        {
            fakeButtonJääkiekko.SetActive(false);
            realButtonJääkiekko.SetActive(true);
        }

        if (turnOffButtonJääkiekko == true)
        {
            fakeButtonJääkiekko.SetActive(true);
            realButtonJääkiekko.SetActive(false);
            turnOffButtonJääkiekko = false;
        }
    }
}
