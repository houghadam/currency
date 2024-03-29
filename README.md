# Currency

#### A simple command-line currency converter written in c

The goal of currency is to be a lightweight, fast, and simple to use currency converter. With support for more than 160 currencies, it provides currency conversions to the most used currencies around the world in seconds using real-time exchange rates from Currency Beacon [title](https://currencybeacon.com).

## Using currency

Currency was designed with ease of use in mind. It uses a simple structure for accepting command-line arguments and prints results right to the terminal.

Arguments should be passed in the following order:

1. Amount to be converted
2. Currency to convert from
3. Currency to convert to
   Note: Any arguments beyond 3 will also be treated as currencies to convert to.

##### Examples:

`$./currency 500 USD EUR`
Converts $500 US Dollars to Euro

`$./currency 675 EUR CNY JPY GBP`
Converts €675 to Chinese Yuan, Japanese Yen, and British Pounds Sterling
