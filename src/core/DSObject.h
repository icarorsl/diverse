

namespace diverse {    

    class DSObject {
        int _number;

        public:
            DSObject();
            DSObject(const int number);
            //virtual ~DSObject() = default;

            int GetNumber() const;
    };

}