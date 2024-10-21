template<int CurrencyConversion>
struct Currency
{
    static const int conversionRate = CurrencyConversion;
    int d_value;
    Currency(int value): d_value(value) { }
};

template<typename OtherCurrency, typename SourceCurrency>
OtherCurrency to(const SourceCurrency& source) {
    float baseValue = source.d_value / float(source.conversionRate);
    int otherCurrencyValue = int(baseValue * OtherCurrency::conversionRate);
    return OtherCurrency(otherCurrencyValue);
}