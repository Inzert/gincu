// Auto generated file, don't modify.

#ifndef CPGF_META_GINCUGCOMPONENTANIMATION_H
#define CPGF_META_GINCUGCOMPONENTANIMATION_H


#include "cpgf/gmetadefine.h"
#include "cpgf/metadata/gmetadataconfig.h"
#include "cpgf/metadata/private/gmetadata_header.h"
#include "cpgf/gmetapolicy.h"


using namespace gincu;


namespace meta_gincu { 


template <typename D>
void buildMetaClass_GComponentAnimation(D _d)
{
    (void)_d;
    using namespace cpgf;
    
    _d.CPGF_MD_TEMPLATE _method("getComponentType", &D::ClassType::getComponentType);
    _d.CPGF_MD_TEMPLATE _method("setAnimation", &D::ClassType::setAnimation, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<0> >());
}


} // namespace meta_gincu




#include "cpgf/metadata/private/gmetadata_footer.h"


#endif
