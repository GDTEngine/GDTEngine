/**
 * @file     ClassManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

namespace gdt
{
    namespace engine
    {
        class CEntity;

        namespace priv
        {
            /**
             * @brief Manager for handling classes.
             */
            class ENGINE_API IClassManager
            {
            public:

                using CreateEntityFunction = CEntity * (*)();

            public:

                virtual ~IClassManager() = default;

                /**
                 * @brief Create an entity.
                 * @param className Name of the entity class.
                 */
                virtual CEntity* createEntity(const std::string& className) = 0;

                /**
                 * @brief Register an entity class.
                 * @param className Name of the entity class.
                 * @param function Function used to create an entity.
                 */
                virtual void registerEntity(const std::string& className, CreateEntityFunction function) = 0;
            };
        }
    }
}
