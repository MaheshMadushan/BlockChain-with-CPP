#undef HFF_H
#ifndef HFF_H
#define HFF_H





/// \brief Object factory interface for registering objects
/// \tparam AbstractClass Base class interface of the object
template <class AbstractClass>
class ObjectFactory
{
public:
	virtual ~ObjectFactory () {}
	virtual AbstractClass * CreateObject() const =0;
};

/// \brief Object factory for registering objects
/// \tparam AbstractClass Base class interface of the object
/// \tparam ConcreteClass Class object
template <class AbstractClass, class ConcreteClass>
class DefaultObjectFactory : public ObjectFactory<AbstractClass>
{
public:
	AbstractClass * CreateObject() const
	{
		return new ConcreteClass;
	}
};

/// \brief Object factory registry
/// \tparam AbstractClass Base class interface of the object
/// \tparam instance unique identifier
template <class AbstractClass, int instance=0>
class ObjectFactoryRegistry
{
public:
	class FactoryNotFound : public Exception
	{
	public:
		FactoryNotFound(const char *name) : Exception(OTHER_ERROR, std::string("ObjectFactoryRegistry: could not find factory for algorithm ") + name)  {}
	};

	~ObjectFactoryRegistry()
	{
		for (typename Map::iterator i = m_map.begin(); i != m_map.end(); ++i)
		{
			delete (ObjectFactory<AbstractClass> *)i->second;
			i->second = NULLPTR;
		}
	}

	void RegisterFactory(const std::string &name, ObjectFactory<AbstractClass> *factory)
	{
		m_map[name] = factory;
	}

	const ObjectFactory<AbstractClass> * GetFactory(const char *name) const
	{
		typename Map::const_iterator i = m_map.find(name);
		return i == m_map.end() ? NULLPTR : (ObjectFactory<AbstractClass> *)i->second;
	}

	AbstractClass *CreateObject(const char *name) const
	{
		const ObjectFactory<AbstractClass> *factory = GetFactory(name);
		if (!factory)
			throw FactoryNotFound(name);
		return factory->CreateObject();
	}

	// Return a vector containing the factory names. This is easier than returning an iterator.
	// from Andrew Pitonyak
	std::vector<std::string> GetFactoryNames() const
	{
		std::vector<std::string> names;
		typename Map::const_iterator iter;
		for (iter = m_map.begin(); iter != m_map.end(); ++iter)
			names.push_back(iter->first);
		return names;
	}

	CRYPTOPP_NOINLINE static ObjectFactoryRegistry<AbstractClass, instance> & Registry(CRYPTOPP_NOINLINE_DOTDOTDOT);

private:
	// use void * instead of ObjectFactory<AbstractClass> * to save code size
	typedef std::map<std::string, void *> Map;
	Map m_map;
};










#endif // HFF_H