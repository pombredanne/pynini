// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Copyright 2016 and onwards Google, Inc.
//
// For general information on the Pynini grammar compilation library, see
// pynini.opengrm.org.

#ifndef CROSSPRODUCTSCRIPT_H_
#define CROSSPRODUCTSCRIPT_H_

#include <string>
using std::string;

#include <fst/script/arg-packs.h>
#include <fst/script/fst-class.h>
#include "crossproduct.h"

namespace fst {
namespace script {

typedef args::Package<const FstClass &, const FstClass &, MutableFstClass *>
    CrossProductArgs;

template <class Arc>
void CrossProduct(CrossProductArgs *args) {
  const Fst<Arc> &ifst1 = *(args->arg1.GetFst<Arc>());
  const Fst<Arc> &ifst2 = *(args->arg2.GetFst<Arc>());
  MutableFst<Arc> *ofst = args->arg3->GetMutableFst<Arc>();
  CrossProduct(ifst1, ifst2, ofst);
}

void CrossProduct(const FstClass &ifst1, const FstClass &ifst2,
                  MutableFstClass *ofst);

template <class Arc>
void OptimizeStringCrossProduct(MutableFstClass *fst) {
  MutableFst<Arc> *typed_fst = fst->GetMutableFst<Arc>();
  OptimizeStringCrossProduct(typed_fst);
}

void OptimizeStringCrossProduct(MutableFstClass *fst);

}  // namespace script
}  // namespace fst

#endif  // CROSSPRODUCTSCRIPT_H_
