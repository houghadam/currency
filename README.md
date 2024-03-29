# Currency

#### A simple, command-line currency converter written in c

The goal of currency is to be a lightweight, fast, and simple to use currency converter. With support for more than 160 currencies, it provides currency conversions to the most used currencies around the world in seconds using real-time exchange rates from [Currency Beacon](https://currencybeacon.com).

## Using currency

Currency was designed with ease of use in mind. It uses a simple structure for accepting command-line arguments and prints results right to the terminal.

Arguments should be passed in the following order:

1. Amount to be converted
2. Currency to convert from
3. Currency to convert to

Notes: All currencies must be entered using their corresponding 3 character code. Conversions to additional currencies can be made by passing additional arguments beyond those required above.

#### Examples:

`$./currency 500 USD EUR`
Converts $500 US Dollars to Euro

`$./currency 675 EUR CNY JPY GBP`
Converts €675 to Chinese Yuan, Japanese Yen, and British Pounds Sterling

## Currency codes
|Code|Name                         |Symbol|
|----|-----------------------------|------|
|AED |UAE Dirham                   |د.إ   |
|AFN |Afghani                      |؋     |
|ALL |Lek                          |L     |
|AMD |Armenian Dram                |դր.   |
|ANG |Netherlands Antillean Guilder|ƒ     |
|AOA |Kwanza                       |Kz    |
|ARS |Argentine Peso               |$     |
|AUD |Australian Dollar            |$     |
|AWG |Aruban Florin                |ƒ     |
|AZN |Azerbaijanian Manat          |₼     |
|BAM |Convertible Mark             |КМ    |
|BBD |Barbados Dollar              |$     |
|BDT |Taka                         |৳     |
|BGN |Bulgarian Lev                |лв    |
|BHD |Bahraini Dinar               |ب.د   |
|BIF |Burundi Franc                |Fr    |
|BMD |Bermudian Dollar             |$     |
|BND |Brunei Dollar                |$     |
|BOB |Boliviano                    |Bs.   |
|BOV |Mvdol                        |Bs.   |
|BRL |Brazilian Real               |R$    |
|BSD |Bahamian Dollar              |$     |
|BTN |Ngultrum                     |Nu.   |
|BWP |Pula                         |P     |
|BYN |Belarussian Ruble            |Br    |
|BZD |Belize Dollar                |$     |
|CAD |Canadian Dollar              |$     |
|CDF |Congolese Franc              |Fr    |
|CHF |Swiss Franc                  |CHF   |
|CLF |Unidades de fomento          |UF    |
|CLP |Chilean Peso                 |$     |
|CNY |Yuan Renminbi                |¥     |
|COP |Colombian Peso               |$     |
|CRC |Costa Rican Colon            |₡     |
|CUC |Peso Convertible             |$     |
|CUP |Cuban Peso                   |$     |
|CVE |Cape Verde Escudo            |$     |
|CZK |Czech Koruna                 |Kč    |
|DJF |Djibouti Franc               |Fdj   |
|DKK |Danish Krone                 |kr    |
|DOP |Dominican Peso               |$     |
|DZD |Algerian Dinar               |د.ج   |
|EGP |Egyptian Pound               |ج.م   |
|ERN |Nakfa                        |Nfk   |
|ETB |Ethiopian Birr               |Br    |
|EUR |Euro                         |€     |
|FJD |Fiji Dollar                  |$     |
|FKP |Falkland Islands Pound       |£     |
|GBP |Pound Sterling               |£     |
|GEL |Lari                         |ლ     |
|GHS |Ghana Cedi                   |₵     |
|GIP |Gibraltar Pound              |£     |
|GMD |Dalasi                       |D     |
|GNF |Guinea Franc                 |Fr    |
|GTQ |Quetzal                      |Q     |
|GYD |Guyana Dollar                |$     |
|HKD |Hong Kong Dollar             |$     |
|HNL |Lempira                      |L     |
|HRK |Croatian Kuna                |kn    |
|HTG |Gourde                       |G     |
|HUF |Forint                       |Ft    |
|IDR |Rupiah                       |Rp    |
|ILS |New Israeli Sheqel           |₪     |
|INR |Indian Rupee                 |₹     |
|IQD |Iraqi Dinar                  |ع.د   |
|IRR |Iranian Rial                 |﷼     |
|ISK |Iceland Krona                |kr    |
|JMD |Jamaican Dollar              |$     |
|JOD |Jordanian Dinar              |د.ا   |
|JPY |Yen                          |¥     |
|KES |Kenyan Shilling              |KSh   |
|KGS |Som                          |som   |
|KHR |Riel                         |៛     |
|KMF |Comoro Franc                 |Fr    |
|KPW |North Korean Won             |₩     |
|KRW |Won                          |₩     |
|KWD |Kuwaiti Dinar                |د.ك   |
|KYD |Cayman Islands Dollar        |$     |
|KZT |Tenge                        |〒     |
|LAK |Kip                          |₭     |
|LBP |Lebanese Pound               |ل.ل   |
|LKR |Sri Lanka Rupee              |₨     |
|LRD |Liberian Dollar              |$     |
|LSL |Loti                         |L     |
|LTL |Lithuanian Litas             |Lt    |
|LVL |Latvian Lats                 |Ls    |
|LYD |Libyan Dinar                 |ل.د   |
|MAD |Moroccan Dirham              |د.م.  |
|MDL |Moldovan Leu                 |L     |
|MGA |Malagasy Ariary              |Ar    |
|MKD |Denar                        |ден   |
|MMK |Kyat                         |K     |
|MNT |Tugrik                       |₮     |
|MOP |Pataca                       |P     |
|MRO |Ouguiya                      |UM    |
|MUR |Mauritius Rupee              |₨     |
|MVR |Rufiyaa                      |MVR   |
|MWK |Kwacha                       |MK    |
|MXN |Mexican Peso                 |$     |
|MYR |Malaysian Ringgit            |RM    |
|MZN |Mozambique Metical           |MTn   |
|NAD |Namibia Dollar               |$     |
|NGN |Naira                        |₦     |
|NIO |Cordoba Oro                  |C$    |
|NOK |Norwegian Krone              |kr    |
|NPR |Nepalese Rupee               |₨     |
|NZD |New Zealand Dollar           |$     |
|OMR |Rial Omani                   |ر.ع.  |
|PAB |Balboa                       |B/.   |
|PEN |Sol                          |S/    |
|PGK |Kina                         |K     |
|PHP |Philippine Peso              |₱     |
|PKR |Pakistan Rupee               |₨     |
|PLN |Zloty                        |zł    |
|PYG |Guarani                      |₲     |
|QAR |Qatari Rial                  |ر.ق   |
|RON |New Romanian Leu             |Lei   |
|RSD |Serbian Dinar                |РСД   |
|RUB |Russian Ruble                |₽     |
|RWF |Rwanda Franc                 |FRw   |
|SAR |Saudi Riyal                  |ر.س   |
|SBD |Solomon Islands Dollar       |$     |
|SCR |Seychelles Rupee             |₨     |
|SDG |Sudanese Pound               |£     |
|SEK |Swedish Krona                |kr    |
|SGD |Singapore Dollar             |$     |
|SHP |Saint Helena Pound           |£     |
|SLL |Leone                        |Le    |
|SOS |Somali Shilling              |Sh    |
|SRD |Surinam Dollar               |$     |
|SSP |South Sudanese Pound         |£     |
|STD |Dobra                        |Db    |
|SVC |El Salvador Colon            |₡     |
|SYP |Syrian Pound                 |£S    |
|SZL |Lilangeni                    |E     |
|THB |Baht                         |฿     |
|TJS |Somoni                       |ЅМ    |
|TMT |Turkmenistan New Manat       |T     |
|TND |Tunisian Dinar               |د.ت   |
|TOP |Pa’anga                      |T$    |
|TRY |Turkish Lira                 |₺     |
|TTD |Trinidad and Tobago Dollar   |$     |
|TWD |New Taiwan Dollar            |$     |
|TZS |Tanzanian Shilling           |Sh    |
|UAH |Hryvnia                      |₴     |
|UGX |Uganda Shilling              |USh   |
|USD |US Dollar                    |$     |
|UYU |Peso Uruguayo                |$     |
|UZS |Uzbekistan Sum               |лв    |
|VEF |Bolivar                      |Bs F  |
|VND |Dong                         |₫     |
|VUV |Vatu                         |Vt    |
|WST |Tala                         |T     |
|XAF |CFA Franc BEAC               |Fr    |
|XCD |East Caribbean Dollar        |$     |
|XOF |CFA Franc BCEAO              |Fr    |
|XPF |CFP Franc                    |Fr    |
|YER |Yemeni Rial                  |﷼     |
|ZAR |Rand                         |R     |
|ZMW |Zambian Kwacha               |ZK    |
|ZWL |Zimbabwe Dollar              |$     |
