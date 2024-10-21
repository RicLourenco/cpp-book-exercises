class Department
{
    public:
        Department(int expectedEarning, int effectiveEarning)
            : d_expectedEarning(expectedEarning),
            d_effectiveEarning(effectiveEarning) { }

        bool hasReachedTarget() const {
            return d_effectiveEarning >= d_expectedEarning;
        }

        int expectedEarning() const {
            return d_expectedEarning;
        }

        int effectiveEarning() const {
            return d_effectiveEarning;
        }

    private:
        int d_expectedEarning;
        int d_effectiveEarning;
};

class Employee
{
    public:
        virtual int getBaseSalary() const {
            return 100;
        }

        virtual int getBonus(const Department& dep) const {
            if (dep.hasReachedTarget()) {
                return int(0.1 * getBaseSalary());
            }

            return 0;
        }

        int getTotalComp(const Department& dep) {
            return getBaseSalary() + getBonus(dep);
        }
};

class Manager : public Employee
{
    public:
        virtual int getBaseSalary() const override {
            return 150;
        }

        virtual int getBonus(const Department& dep) const override {
            if (dep.hasReachedTarget()) {
                int additionalDeparmentEarnings = dep.effectiveEarning() - dep.expectedEarning();
                return int(0.2 * getBaseSalary() + 0.01 * additionalDeparmentEarnings);
            }

            return 0;
        }
};