#ifndef CreationalDesignPatterns_hpp
#define CreationalDesignPatterns_hpp

namespace CreationalDesignPatterns {
    namespace products {

        class Product {
            public:
                Product() = default;
                virtual ~Product() = default;
                virtual void virtualMethod() const;
        };

        class Product1: public Product {
            private:
                void* settings;
            public:
                void setSettings(const void* settings) const;
                const Product1& clone() const {
                    return *this;
                }
                virtual void virtualMethod() const override;
        };

        class Product2: public Product {
            private:
                void* settings;
            public:
                void setSettings(const void* settings) const;
                const Product2& clone() const {
                    return *this;
                }
                virtual void virtualMethod() const override;
        };

        // Product2 category
        class Product2bis: public Product2 {
            private:
                void* otherSettings;
            public:
                void setSettings(const void* otherSettings) const;
                const Product2bis& clone() const {
                    return *this;
                }
                virtual void virtualMethod() const override;
        };

        class Product3: public Product {
            private:
                void* settings;
            public:
                void setSettings(const void* settings) const;
                const Product3& clone() const {
                    return *this;
                }
                virtual void virtualMethod() const override;
        };

    } /* products */

    namespace factories {
        using namespace products;

        enum class FactoryType : unsigned {
            Default,
            Prototype
        };

        // This is a Singleton
        class Factory {
            private:
                static Factory* instance_;

            protected:
                Factory() = default;

            public:
                const Factory& Instance(const FactoryType& type) const;

                virtual const Product1& makeProduct1(const void* settings) const;
                virtual const Product2& makeProduct2(const void* settings) const;
                virtual const Product3& makeProduct3(const void* settings) const;
        };

        class DefaultFactory: public Factory {
            public:
                virtual const Product1& makeProduct1(const void* settings) const override;
                virtual const Product2& makeProduct2(const void* settings) const override;
                virtual const Product3& makeProduct3(const void* settings) const override;
        };

        // prototype
        class PrototypeFactory: public Factory {
            private:
                Product1 prototypeProduct1;
                Product2 prototypeProduct2;
                Product3 prototypeProduct3;

            public:
                PrototypeFactory(const Product1& product1, const Product2& product2, const Product3& product3)
                    : prototypeProduct1(product1), prototypeProduct2(product2), prototypeProduct3(product3) {};
                virtual ~PrototypeFactory() = default;

                virtual const Product1& makeProduct1(const void* settings) const override {
                    return prototypeProduct1;
                }
                virtual const Product2& makeProduct2(const void* settings) const override;
                virtual const Product3& makeProduct3(const void* settings) const override;
        };

        const Factory& Factory::Instance(const FactoryType& type) const {
            if (instance_ == nullptr) {
                if (type == FactoryType::Default) {
                    instance_ = new DefaultFactory;
                } else if (type == FactoryType::Prototype) {
                    instance_ = new PrototypeFactory(Product1(), Product2(), Product3());
                } else {
                    instance_ = new Factory;
                }

            }
            return *instance_;
        };


    } /* factories */

    namespace builders {
        using namespace products;

        class Builder {
            public:
                virtual void buildProduct1(const void* settings);
                virtual const Product1& getProduct1() const;

                virtual void buildProduct2(const void* settings);
                virtual const Product2& getProduct2() const;

                virtual void buildProduct3(const void* settings);
                virtual const Product3& getProduct3() const;

            protected:
                Builder() = default;
        };

        class DefaultBuilder: public Builder {
            private:
                Product1* currentProduct1;
                Product2* currentProduct2;
                Product3* currentProduct3;

            public:
                DefaultBuilder() = default;

                virtual void buildProduct1(const void* settings) override {
                    currentProduct1 = new Product1;
                    currentProduct1->setSettings(settings);
                }
                virtual const Product1& getProduct1() const override { return *currentProduct1; }

                virtual void buildProduct2(const void* settings) override {
                    currentProduct2 = new Product2;
                    currentProduct2->setSettings(settings);
                }
                virtual const Product2& getProduct2() const override  { return *currentProduct2; }

                virtual void buildProduct3(const void* settings) override {
                    currentProduct3 = new Product3;
                    currentProduct3->setSettings(settings);
                }
                virtual const Product3& getProduct3() const override  { return *currentProduct3; }
        };

    } /* builders */

    namespace entity {
        using namespace factories;
        using namespace builders;

        class Entity {
            private:
                Product1 theProduct1;
                Product2 theProduct2;
                Product3 theProduct3;

            public:
                Entity() = default;
                virtual ~Entity() = default;

                void make(const Factory& factory);
                void make(const Builder& builder);

                // factory methods
                virtual void makeProduct1(const void* settings) const;
                virtual void makeProduct2(const void* settings) const;
                virtual void makeProduct3(const void* settings) const;

        };

        class ModifiedEntity: public Entity {
        public:
            ModifiedEntity() = default;
            virtual ~ModifiedEntity() = default;

            // factory methods
            virtual void makeProduct1(const void* settings) const override;
            virtual void makeProduct2(const void* settings) const override;
            virtual void makeProduct3(const void* settings) const override;
        };

    } /* entity */

} /* CreationalDesignPatterns */

#endif /* end of include guard: CreationalDesignPatterns_hpp */
