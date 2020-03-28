/* Generated code for Python module '__main__'
 * created by Nuitka version 0.6.7
 *
 * This code is in part copyright 2019 Kay Hayen.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "nuitka/prelude.h"

#include "__helpers.h"

/* The "_module___main__" is a Python object pointer of module type.
 *
 * Note: For full compatibility with CPython, every module variable access
 * needs to go through it except for cases where the module cannot possibly
 * have changed in the mean time.
 */

PyObject *module___main__;
PyDictObject *moduledict___main__;

/* The declarations of module constants used, if any. */
static PyObject *const_str_digest_f6d6cc00f060d6e2f31f38f19b48443c;
static PyObject *const_str_plain_length;
extern PyObject *const_str_plain_decrypt;
extern PyObject *const_str_plain_MED;
static PyObject *const_str_digest_3d86b0fa60a546d30bce814f02c93d46;
static PyObject *const_int_pos_256;
static PyObject *const_str_chr_42;
static PyObject *const_dict_b2cc954541260c68ff55aca1b97f76b4;
static PyObject *const_str_plain_itertools;
static PyObject *const_tuple_str_chr_42_tuple;
static PyObject *const_str_digest_2763934b8069096d2af525dfc5df92fe;
extern PyObject *const_str_plain_crypt;
extern PyObject *const_str_plain_dec;
extern PyObject *const_str_plain_len;
static PyObject *const_str_plain_True;
static PyObject *const_str_plain_magic_dec;
extern PyObject *const_str_plain_bytearray;
extern PyObject *const_str_plain_site;
static PyObject *const_str_plain_per;
static PyObject *const_str_plain_psw_cand;
static PyObject *const_tuple_int_pos_16777216_tuple;
static PyObject *const_str_plain_count;
static PyObject *const_str_plain_version;
static PyObject *const_str_plain_psw_strength;
extern PyObject *const_str_plain_HIG;
extern PyObject *const_str_plain_MAGIC;
extern PyObject *const_str_plain___doc__;
static PyObject *const_str_digest_ade85897a9b8cb0557ea23d536f9bdc2;
static PyObject *const_str_plain_it;
extern PyObject *const_str_plain_read;
extern PyObject *const_int_0;
static PyObject *const_str_plain_max_strength;
extern PyObject *const_str_plain_sys;
static PyObject *const_str_plain_psw_fnd;
extern PyObject *const_str_plain___file__;
static PyObject *const_int_pos_10000;
extern PyObject *const_int_pos_6;
static PyObject *const_str_angle_module;
extern PyObject *const_str_plain_cipher;
extern PyObject *const_int_pos_7;
extern PyObject *const_str_plain_pswchars;
extern PyObject *const_int_pos_5;
extern PyObject *const_int_pos_2;
extern PyObject *const_str_plain_b;
extern PyObject *const_str_plain_join;
extern PyObject *const_int_pos_1;
extern PyObject *const_str_empty;
extern PyObject *const_str_plain_cnt;
extern PyObject *const_tuple_empty;
static PyObject *const_str_plain_permutations;
extern PyObject *const_str_plain_False;
extern PyObject *const_str_digest_7362b9a47180204a87d7e3a16823d69f;
extern PyObject *const_int_pos_3;
static PyObject *const_tuple_int_pos_256_tuple;
extern PyObject *const_str_plain_i;
static PyObject *const_str_plain_min_strength;
extern PyObject *const_str_plain_f;
static PyObject *const_str_digest_1c866ea462750c72e2bf4ed1feb7001c;
extern PyObject *const_str_plain_close;
extern PyObject *const_int_pos_4;
static PyObject *const_str_digest_3fa1e2f311007397326c4d971b118c69;
extern PyObject *const_str_plain_rb;
static PyObject *const_int_pos_20;
static PyObject *const_int_pos_16777216;
static PyObject *const_str_plain_input;
static PyObject *const_str_plain_magic_cnt;
static PyObject *const_str_plain_filename;
extern PyObject *const_str_plain_range;
extern PyObject *const_str_plain_argv;
extern PyObject *const_str_plain_open;
static PyObject *module_filename_obj;

/* Indicator if this modules private constants were created yet. */
static bool constants_created = false;

/* Function to create module private constants. */
static void createModuleConstants(void) {
    const_str_digest_f6d6cc00f060d6e2f31f38f19b48443c = UNSTREAM_STRING(&constant_bin[ 1035 ], 9, 0);
    const_str_plain_length = UNSTREAM_STRING(&constant_bin[ 572 ], 6, 1);
    const_str_digest_3d86b0fa60a546d30bce814f02c93d46 = UNSTREAM_STRING(&constant_bin[ 1044 ], 11, 0);
    const_int_pos_256 = PyInt_FromLong(256l);
    const_str_chr_42 = UNSTREAM_CHAR(42, 0);
    const_dict_b2cc954541260c68ff55aca1b97f76b4 = _PyDict_NewPresized( 1 );
    PyDict_SetItem(const_dict_b2cc954541260c68ff55aca1b97f76b4, const_str_plain_crypt, const_str_plain_dec);
    assert(PyDict_Size(const_dict_b2cc954541260c68ff55aca1b97f76b4) == 1);
    const_str_plain_itertools = UNSTREAM_STRING(&constant_bin[ 1055 ], 9, 1);
    const_tuple_str_chr_42_tuple = PyTuple_New(1);
    PyTuple_SET_ITEM(const_tuple_str_chr_42_tuple, 0, const_str_chr_42); Py_INCREF(const_str_chr_42);
    const_str_digest_2763934b8069096d2af525dfc5df92fe = UNSTREAM_STRING(&constant_bin[ 1064 ], 12, 0);
    const_str_plain_True = UNSTREAM_STRING(&constant_bin[ 478 ], 4, 1);
    const_str_plain_magic_dec = UNSTREAM_STRING(&constant_bin[ 1076 ], 9, 1);
    const_str_plain_per = UNSTREAM_STRING(&constant_bin[ 654 ], 3, 1);
    const_str_plain_psw_cand = UNSTREAM_STRING(&constant_bin[ 421 ], 8, 1);
    const_tuple_int_pos_16777216_tuple = PyTuple_New(1);
    const_int_pos_16777216 = PyInt_FromLong(16777216l);
    PyTuple_SET_ITEM(const_tuple_int_pos_16777216_tuple, 0, const_int_pos_16777216); Py_INCREF(const_int_pos_16777216);
    const_str_plain_count = UNSTREAM_STRING(&constant_bin[ 334 ], 5, 1);
    const_str_plain_version = UNSTREAM_STRING(&constant_bin[ 276 ], 7, 1);
    const_str_plain_psw_strength = UNSTREAM_STRING(&constant_bin[ 157 ], 12, 1);
    const_str_digest_ade85897a9b8cb0557ea23d536f9bdc2 = UNSTREAM_STRING(&constant_bin[ 1085 ], 65, 0);
    const_str_plain_it = UNSTREAM_STRING(&constant_bin[ 600 ], 2, 1);
    const_str_plain_max_strength = UNSTREAM_STRING(&constant_bin[ 538 ], 12, 1);
    const_str_plain_psw_fnd = UNSTREAM_STRING(&constant_bin[ 305 ], 7, 1);
    const_int_pos_10000 = PyInt_FromLong(10000l);
    const_str_angle_module = UNSTREAM_STRING(&constant_bin[ 1150 ], 8, 0);
    const_str_plain_permutations = UNSTREAM_STRING(&constant_bin[ 1158 ], 12, 1);
    const_tuple_int_pos_256_tuple = PyTuple_New(1);
    PyTuple_SET_ITEM(const_tuple_int_pos_256_tuple, 0, const_int_pos_256); Py_INCREF(const_int_pos_256);
    const_str_plain_min_strength = UNSTREAM_STRING(&constant_bin[ 504 ], 12, 1);
    const_str_digest_1c866ea462750c72e2bf4ed1feb7001c = UNSTREAM_STRING(&constant_bin[ 1170 ], 12, 0);
    const_str_digest_3fa1e2f311007397326c4d971b118c69 = UNSTREAM_STRING(&constant_bin[ 1182 ], 12, 0);
    const_int_pos_20 = PyInt_FromLong(20l);
    const_str_plain_input = UNSTREAM_STRING(&constant_bin[ 56 ], 5, 1);
    const_str_plain_magic_cnt = UNSTREAM_STRING(&constant_bin[ 390 ], 9, 1);
    const_str_plain_filename = UNSTREAM_STRING(&constant_bin[ 1194 ], 8, 1);

    constants_created = true;
}

/* Function to verify module private constants for non-corruption. */
#ifndef __NUITKA_NO_ASSERT__
void checkModuleConstants___main__(void) {
    // The module may not have been used at all, then ignore this.
    if (constants_created == false) return;


}
#endif

// The module code objects.
static PyCodeObject *codeobj_2fed2079e999b99c6812552efed77f38;
/* For use in "MainProgram.c". */
PyCodeObject *codeobj_main = NULL;

static void createModuleCodeObjects(void) {
    module_filename_obj = const_str_digest_ade85897a9b8cb0557ea23d536f9bdc2;
    codeobj_2fed2079e999b99c6812552efed77f38 = MAKE_CODEOBJECT(module_filename_obj, 1, CO_NOFREE, const_str_angle_module, const_tuple_empty, 0, 0, 0);
}

// The module function declarations.


// The module function definitions.



#if PYTHON_VERSION >= 300
static struct PyModuleDef mdef___main__ =
{
    PyModuleDef_HEAD_INIT,
    NULL,                /* m_name, filled later */
    NULL,                /* m_doc */
    -1,                  /* m_size */
    NULL,                /* m_methods */
    NULL,                /* m_reload */
    NULL,                /* m_traverse */
    NULL,                /* m_clear */
    NULL,                /* m_free */
  };
#endif

extern PyObject *const_str_plain___compiled__;

extern PyObject *const_str_plain___package__;
extern PyObject *const_str_empty;

#if PYTHON_VERSION >= 300
extern PyObject *const_str_dot;
extern PyObject *const_str_plain___loader__;
#endif

#if PYTHON_VERSION >= 340
extern PyObject *const_str_plain___spec__;
extern PyObject *const_str_plain__initializing;
extern PyObject *const_str_plain_submodule_search_locations;
#endif

extern void _initCompiledCellType();
extern void _initCompiledGeneratorType();
extern void _initCompiledFunctionType();
extern void _initCompiledMethodType();
extern void _initCompiledFrameType();
#if PYTHON_VERSION >= 350
extern void _initCompiledCoroutineTypes();
#endif
#if PYTHON_VERSION >= 360
extern void _initCompiledAsyncgenTypes();
#endif

extern PyTypeObject Nuitka_Loader_Type;

#ifdef _NUITKA_PLUGIN_DILL_ENABLED
// Provide a way to create find a function via its C code and create it back
// in another process, useful for multiprocessing extensions like dill

function_impl_code functable___main__[] = {

    NULL
};

static char const *_reduce_compiled_function_argnames[] = {
    "func",
    NULL
};

static PyObject *_reduce_compiled_function(PyObject *self, PyObject *args, PyObject *kwds) {
    PyObject *func;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:reduce_compiled_function", (char **)_reduce_compiled_function_argnames, &func, NULL)) {
        return NULL;
    }

    if (Nuitka_Function_Check(func) == false) {
        PyErr_Format(PyExc_TypeError, "not a compiled function");
        return NULL;
    }

    struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)func;

    function_impl_code *current = functable___main__;
    int offset = 0;

    while (*current != NULL) {
        if (*current == function->m_c_code) {
            break;
        }

        current += 1;
        offset += 1;
    }

    if (*current == NULL) {
        PyErr_Format(PyExc_TypeError, "Cannot find compiled function in module.");
        return NULL;
    }

    PyObject *code_object_desc = PyTuple_New(6);
    PyTuple_SET_ITEM0(code_object_desc, 0, function->m_code_object->co_filename);
    PyTuple_SET_ITEM0(code_object_desc, 1, function->m_code_object->co_name);
    PyTuple_SET_ITEM(code_object_desc, 2, PyLong_FromLong(function->m_code_object->co_firstlineno));
    PyTuple_SET_ITEM0(code_object_desc, 3, function->m_code_object->co_varnames);
    PyTuple_SET_ITEM(code_object_desc, 4, PyLong_FromLong(function->m_code_object->co_argcount));
    PyTuple_SET_ITEM(code_object_desc, 5, PyLong_FromLong(function->m_code_object->co_flags));

    CHECK_OBJECT_DEEP(code_object_desc);

    PyObject *result = PyTuple_New(4);
    PyTuple_SET_ITEM(result, 0, PyLong_FromLong(offset));
    PyTuple_SET_ITEM(result, 1, code_object_desc);
    PyTuple_SET_ITEM0(result, 2, function->m_defaults);
    PyTuple_SET_ITEM0(result, 3, function->m_doc != NULL ? function->m_doc : Py_None);

    CHECK_OBJECT_DEEP(result);

    return result;
}

static PyMethodDef _method_def_reduce_compiled_function = {"reduce_compiled_function", (PyCFunction)_reduce_compiled_function,
                                                           METH_VARARGS | METH_KEYWORDS, NULL};

static char const *_create_compiled_function_argnames[] = {
    "func",
    "code_object_desc",
    "defaults",
    "doc",
    NULL
};


static PyObject *_create_compiled_function(PyObject *self, PyObject *args, PyObject *kwds) {
    CHECK_OBJECT_DEEP(args);

    PyObject *func;
    PyObject *code_object_desc;
    PyObject *defaults;
    PyObject *doc;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "OOOO:create_compiled_function", (char **)_create_compiled_function_argnames, &func, &code_object_desc, &defaults, &doc, NULL)) {
        return NULL;
    }

    int offset = PyLong_AsLong(func);

    if (offset == -1 && ERROR_OCCURRED()) {
        return NULL;
    }

    if (offset > sizeof(functable___main__) || offset < 0) {
        PyErr_Format(PyExc_TypeError, "Wrong offset for compiled function.");
        return NULL;
    }

    PyObject *filename = PyTuple_GET_ITEM(code_object_desc, 0);
    PyObject *function_name = PyTuple_GET_ITEM(code_object_desc, 1);
    PyObject *line = PyTuple_GET_ITEM(code_object_desc, 2);
    int line_int = PyLong_AsLong(line);
    assert(!ERROR_OCCURRED());

    PyObject *argnames = PyTuple_GET_ITEM(code_object_desc, 3);
    PyObject *arg_count = PyTuple_GET_ITEM(code_object_desc, 4);
    int arg_count_int = PyLong_AsLong(arg_count);
    assert(!ERROR_OCCURRED());
    PyObject *flags = PyTuple_GET_ITEM(code_object_desc, 5);
    int flags_int = PyLong_AsLong(flags);
    assert(!ERROR_OCCURRED());

    PyCodeObject *code_object = MAKE_CODEOBJECT(
        filename,
        line_int,
        flags_int,
        function_name,
        argnames,
        arg_count_int,
        0, // TODO: Missing kw_only_count
        0 // TODO: Missing pos_only_count
    );

    // TODO: More stuff needed for Python3, best to re-order arguments of MAKE_CODEOBJECT.
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        functable___main__[offset],
        code_object->co_name,
#if PYTHON_VERSION >= 300
        NULL, // TODO: Not transferring qualname yet
#endif
        code_object,
        defaults,
#if PYTHON_VERSION >= 300
        NULL, // kwdefaults are done on the outside currently
        NULL, // TODO: Not transferring annotations
#endif
        module___main__,
        doc,
        0
    );

    return (PyObject *)result;
}

static PyMethodDef _method_def_create_compiled_function = {
    "create_compiled_function",
    (PyCFunction)_create_compiled_function,
    METH_VARARGS | METH_KEYWORDS, NULL
};


#endif

// Internal entry point for module code.
PyObject *modulecode___main__(char const *module_full_name) {
#if defined(_NUITKA_EXE) || PYTHON_VERSION >= 300
    static bool _init_done = false;

    // Modules might be imported repeatedly, which is to be ignored.
    if (_init_done) {
        return module___main__;
    } else {
        _init_done = true;
    }
#endif

#ifdef _NUITKA_MODULE
    // In case of a stand alone extension module, need to call initialization
    // the init here because that's the first and only time we are going to get
    // called here.

    // May have to activate constants blob.
#if defined(_NUITKA_CONSTANTS_FROM_RESOURCE)
    loadConstantsResource();
#endif

    // Initialize the constant values used.
    _initBuiltinModule();
    createGlobalConstants();

    /* Initialize the compiled types of Nuitka. */
    _initCompiledCellType();
    _initCompiledGeneratorType();
    _initCompiledFunctionType();
    _initCompiledMethodType();
    _initCompiledFrameType();
#if PYTHON_VERSION >= 350
    _initCompiledCoroutineTypes();
#endif
#if PYTHON_VERSION >= 360
    _initCompiledAsyncgenTypes();
#endif

#if PYTHON_VERSION < 300
    _initSlotCompare();
#endif
#if PYTHON_VERSION >= 270
    _initSlotIternext();
#endif

    patchBuiltinModule();
    patchTypeComparison();

    // Enable meta path based loader if not already done.
#ifdef _NUITKA_TRACE
    PRINT_STRING("__main__: Calling setupMetaPathBasedLoader().\n");
#endif
    setupMetaPathBasedLoader();

#if PYTHON_VERSION >= 300
    patchInspectModule();
#endif

#endif

    /* The constants only used by this module are created now. */
#ifdef _NUITKA_TRACE
    PRINT_STRING("__main__: Calling createModuleConstants().\n");
#endif
    createModuleConstants();

    /* The code objects used by this module are created now. */
#ifdef _NUITKA_TRACE
    PRINT_STRING("__main__: Calling createModuleCodeObjects().\n");
#endif
    createModuleCodeObjects();

    // PRINT_STRING("in init__main__\n");

    // Create the module object first. There are no methods initially, all are
    // added dynamically in actual code only.  Also no "__doc__" is initially
    // set at this time, as it could not contain NUL characters this way, they
    // are instead set in early module code.  No "self" for modules, we have no
    // use for it.
#if PYTHON_VERSION < 300
    module___main__ = Py_InitModule4(
        module_full_name,        // Module Name
        NULL,                    // No methods initially, all are added
                                 // dynamically in actual module code only.
        NULL,                    // No "__doc__" is initially set, as it could
                                 // not contain NUL this way, added early in
                                 // actual code.
        NULL,                    // No self for modules, we don't use it.
        PYTHON_API_VERSION
    );
#else
    mdef___main__.m_name = module_full_name;
    module___main__ = PyModule_Create(&mdef___main__);
#endif

    moduledict___main__ = MODULE_DICT(module___main__);

#ifdef _NUITKA_PLUGIN_DILL_ENABLED
    {
        PyObject *function_tables = PyObject_GetAttrString((PyObject *)builtin_module, "compiled_function_tables");
        if (function_tables == NULL)
        {
            DROP_ERROR_OCCURRED();
            function_tables = PyDict_New();
        }
        PyObject_SetAttrString((PyObject *)builtin_module, "compiled_function_tables", function_tables);
        PyObject *funcs = PyTuple_New(2);
        PyTuple_SetItem(funcs, 0, PyCFunction_New(&_method_def_reduce_compiled_function, NULL));
        PyTuple_SetItem(funcs, 1, PyCFunction_New(&_method_def_create_compiled_function, NULL));
        PyDict_SetItemString(function_tables, module_full_name, funcs);
    }
#endif

    // Set "__compiled__" to what version information we have.
    UPDATE_STRING_DICT0(
        moduledict___main__,
        (Nuitka_StringObject *)const_str_plain___compiled__,
        Nuitka_dunder_compiled_value
    );

    // Update "__package__" value to what it ought to be.
    {
#if 0
        UPDATE_STRING_DICT0(
            moduledict___main__,
            (Nuitka_StringObject *)const_str_plain___package__,
            const_str_empty
        );
#elif 0
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain___name__);

        UPDATE_STRING_DICT0(
            moduledict___main__,
            (Nuitka_StringObject *)const_str_plain___package__,
            module_name
        );
#else

#if PYTHON_VERSION < 300
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain___name__);
        char const *module_name_cstr = PyString_AS_STRING(module_name);

        char const *last_dot = strrchr(module_name_cstr, '.');

        if (last_dot != NULL)
        {
            UPDATE_STRING_DICT1(
                moduledict___main__,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyString_FromStringAndSize(module_name_cstr, last_dot - module_name_cstr)
            );
        }
#else
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain___name__);
        Py_ssize_t dot_index = PyUnicode_Find(module_name, const_str_dot, 0, PyUnicode_GetLength(module_name), -1);

        if (dot_index != -1)
        {
            UPDATE_STRING_DICT1(
                moduledict___main__,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyUnicode_Substring(module_name, 0, dot_index)
            );
        }
#endif
#endif
    }

    CHECK_OBJECT(module___main__);

// Seems to work for Python2.7 out of the box, but for Python3, the module
// doesn't automatically enter "sys.modules", so do it manually.
#if PYTHON_VERSION >= 300
    {
        int r = PyDict_SetItemString(PyImport_GetModuleDict(), module_full_name, module___main__);
        assert(r != -1);
    }
#endif

    // For deep importing of a module we need to have "__builtins__", so we set
    // it ourselves in the same way than CPython does. Note: This must be done
    // before the frame object is allocated, or else it may fail.

    if (GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain___builtins__) == NULL)
    {
        PyObject *value = (PyObject *)builtin_module;

        // Check if main module, not a dict then but the module itself.
#if !defined(_NUITKA_EXE) || !1
        value = PyModule_GetDict(value);
#endif

        UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain___builtins__, value);
    }

#if PYTHON_VERSION >= 300
    UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain___loader__, (PyObject *)&Nuitka_Loader_Type);
#endif

#if PYTHON_VERSION >= 340
// Set the "__spec__" value

#if 1
    // Main modules just get "None" as spec.
    UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain___spec__, Py_None);
#else
    // Other modules get a "ModuleSpec" from the standard mechanism.
    {
        PyObject *bootstrap_module = PyImport_ImportModule("importlib._bootstrap");
        CHECK_OBJECT(bootstrap_module);
        PyObject *module_spec_class = PyObject_GetAttrString(bootstrap_module, "ModuleSpec");
        Py_DECREF(bootstrap_module);

        PyObject *args[] = {
            GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain___name__),
            (PyObject *)&Nuitka_Loader_Type
        };

        PyObject *spec_value = CALL_FUNCTION_WITH_ARGS2(
            module_spec_class,
            args
        );
        Py_DECREF(module_spec_class);

        // We can assume this to never fail, or else we are in trouble anyway.
        CHECK_OBJECT(spec_value);

// For packages set the submodule search locations as well, even if to empty
// list, so investigating code will consider it a package.
#if 0
        SET_ATTRIBUTE(spec_value, const_str_plain_submodule_search_locations, PyList_New(0));
#endif

// Mark the execution in the "__spec__" value.
        SET_ATTRIBUTE(spec_value, const_str_plain__initializing, Py_True);

        UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain___spec__, spec_value);
    }
#endif
#endif

    // Temp variables if any
    PyObject *tmp_for_loop_1__for_iterator = NULL;
    PyObject *tmp_for_loop_1__iter_value = NULL;
    PyObject *tmp_for_loop_2__for_iterator = NULL;
    PyObject *tmp_for_loop_2__iter_value = NULL;
    PyObject *tmp_for_loop_3__for_iterator = NULL;
    PyObject *tmp_for_loop_3__iter_value = NULL;
    PyObject *tmp_list_contraction_1__$0 = NULL;
    PyObject *tmp_list_contraction_1__contraction_result = NULL;
    PyObject *tmp_list_contraction_1__iter_value_0 = NULL;
    struct Nuitka_FrameObject *frame_2fed2079e999b99c6812552efed77f38;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    bool tmp_result;
    int tmp_res;
    PyObject *tmp_print_value;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;
    PyObject *tmp_inplace_orig;
    PyObject *exception_keeper_type_2;
    PyObject *exception_keeper_value_2;
    PyTracebackObject *exception_keeper_tb_2;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_2;
    PyObject *exception_keeper_type_3;
    PyObject *exception_keeper_value_3;
    PyTracebackObject *exception_keeper_tb_3;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_3;
    PyObject *exception_keeper_type_4;
    PyObject *exception_keeper_value_4;
    PyTracebackObject *exception_keeper_tb_4;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_4;

    // Module code.
    // Frame without reuse.
    frame_2fed2079e999b99c6812552efed77f38 = MAKE_MODULE_FRAME(codeobj_2fed2079e999b99c6812552efed77f38, module___main__);

    // Push the new frame as the currently active one, and we should be exclusively
    // owning it.
    pushFrameStack(frame_2fed2079e999b99c6812552efed77f38);
    assert(Py_REFCNT(frame_2fed2079e999b99c6812552efed77f38) == 2);

    // Framed code:
    {
        PyObject *tmp_name_name_1;
        PyObject *tmp_level_name_1;
        PyObject *tmp_imported_value_1;
        tmp_name_name_1 = const_str_plain_site;
        tmp_level_name_1 = const_int_0;
        frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 1;
        tmp_imported_value_1 = IMPORT_MODULE_KW(tmp_name_name_1, NULL, NULL, NULL, tmp_level_name_1);
        if (tmp_imported_value_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        Py_DECREF(tmp_imported_value_1);
    }
    {
        PyObject *tmp_assign_source_1;
        tmp_assign_source_1 = Py_None;
        UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain___doc__, tmp_assign_source_1);
    }
    {
        PyObject *tmp_assign_source_2;
        tmp_assign_source_2 = const_str_digest_ade85897a9b8cb0557ea23d536f9bdc2;
        UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain___file__, tmp_assign_source_2);
    }
    {
        PyObject *tmp_assign_source_3;
        PyObject *tmp_name_name_2;
        PyObject *tmp_globals_name_1;
        PyObject *tmp_locals_name_1;
        PyObject *tmp_fromlist_name_1;
        tmp_name_name_2 = const_str_plain_itertools;
        tmp_globals_name_1 = (PyObject *)moduledict___main__;
        tmp_locals_name_1 = Py_None;
        tmp_fromlist_name_1 = Py_None;
        frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 1;
        tmp_assign_source_3 = IMPORT_MODULE4(tmp_name_name_2, tmp_globals_name_1, tmp_locals_name_1, tmp_fromlist_name_1);
        if (tmp_assign_source_3 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_it, tmp_assign_source_3);
    }
    {
        PyObject *tmp_assign_source_4;
        PyObject *tmp_name_name_3;
        PyObject *tmp_globals_name_2;
        PyObject *tmp_locals_name_2;
        PyObject *tmp_fromlist_name_2;
        tmp_name_name_3 = const_str_plain_sys;
        tmp_globals_name_2 = (PyObject *)moduledict___main__;
        tmp_locals_name_2 = Py_None;
        tmp_fromlist_name_2 = Py_None;
        frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 2;
        tmp_assign_source_4 = IMPORT_MODULE4(tmp_name_name_3, tmp_globals_name_2, tmp_locals_name_2, tmp_fromlist_name_2);
        assert(!(tmp_assign_source_4 == NULL));
        UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_sys, tmp_assign_source_4);
    }
    {
        PyObject *tmp_star_imported_1;
        PyObject *tmp_name_name_4;
        PyObject *tmp_globals_name_3;
        PyObject *tmp_locals_name_3;
        PyObject *tmp_fromlist_name_3;
        tmp_name_name_4 = const_str_plain_cipher;
        tmp_globals_name_3 = (PyObject *)moduledict___main__;
        tmp_locals_name_3 = (PyObject *)moduledict___main__;
        tmp_fromlist_name_3 = const_tuple_str_chr_42_tuple;
        frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 3;
        tmp_star_imported_1 = IMPORT_MODULE4(tmp_name_name_4, tmp_globals_name_3, tmp_locals_name_3, tmp_fromlist_name_3);
        if (tmp_star_imported_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 3;

            goto frame_exception_exit_1;
        }
        tmp_result = IMPORT_MODULE_STAR(module___main__, true, tmp_star_imported_1);
        Py_DECREF(tmp_star_imported_1);
        if (tmp_result == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 3;

            goto frame_exception_exit_1;
        }
    }
    {
        nuitka_bool tmp_condition_result_1;
        PyObject *tmp_compexpr_left_1;
        PyObject *tmp_compexpr_right_1;
        PyObject *tmp_called_name_1;
        PyObject *tmp_mvar_value_1;
        PyObject *tmp_args_element_name_1;
        PyObject *tmp_source_name_1;
        PyObject *tmp_mvar_value_2;
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_len);

        if (unlikely(tmp_mvar_value_1 == NULL)) {
            tmp_mvar_value_1 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_len);
        }

        if (tmp_mvar_value_1 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 25, 0);
            exception_tb = NULL;

            exception_lineno = 5;

            goto frame_exception_exit_1;
        }

        tmp_called_name_1 = tmp_mvar_value_1;
        tmp_mvar_value_2 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_sys);

        if (unlikely(tmp_mvar_value_2 == NULL)) {
            tmp_mvar_value_2 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_sys);
        }

        if (tmp_mvar_value_2 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 25 ], 25, 0);
            exception_tb = NULL;

            exception_lineno = 5;

            goto frame_exception_exit_1;
        }

        tmp_source_name_1 = tmp_mvar_value_2;
        tmp_args_element_name_1 = LOOKUP_ATTRIBUTE(tmp_source_name_1, const_str_plain_argv);
        if (tmp_args_element_name_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 5;

            goto frame_exception_exit_1;
        }
        frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 5;
        tmp_compexpr_left_1 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_1, tmp_args_element_name_1);
        Py_DECREF(tmp_args_element_name_1);
        if (tmp_compexpr_left_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 5;

            goto frame_exception_exit_1;
        }
        tmp_compexpr_right_1 = const_int_pos_2;
        tmp_res = RICH_COMPARE_BOOL_NOTEQ_OBJECT_INT(tmp_compexpr_left_1, tmp_compexpr_right_1);
        Py_DECREF(tmp_compexpr_left_1);
        if (tmp_res == -1) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 5;

            goto frame_exception_exit_1;
        }
        tmp_condition_result_1 = (tmp_res != 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
        if (tmp_condition_result_1 == NUITKA_BOOL_TRUE) {
            goto branch_yes_1;
        } else {
            goto branch_no_1;
        }
        branch_yes_1:;
        {
            PyObject *tmp_assign_source_5;
            PyObject *tmp_called_name_2;
            PyObject *tmp_mvar_value_3;
            tmp_mvar_value_3 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_input);

            if (unlikely(tmp_mvar_value_3 == NULL)) {
                tmp_mvar_value_3 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_input);
            }

            if (tmp_mvar_value_3 == NULL) {

                exception_type = PyExc_NameError;
                Py_INCREF(exception_type);
                exception_value = UNSTREAM_STRING(&constant_bin[ 50 ], 27, 0);
                exception_tb = NULL;

                exception_lineno = 6;

                goto frame_exception_exit_1;
            }

            tmp_called_name_2 = tmp_mvar_value_3;
            frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 6;
            tmp_assign_source_5 = CALL_FUNCTION_NO_ARGS(tmp_called_name_2);
            if (tmp_assign_source_5 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 6;

                goto frame_exception_exit_1;
            }
            UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_filename, tmp_assign_source_5);
        }
        goto branch_end_1;
        branch_no_1:;
        {
            PyObject *tmp_assign_source_6;
            PyObject *tmp_subscribed_name_1;
            PyObject *tmp_source_name_2;
            PyObject *tmp_mvar_value_4;
            PyObject *tmp_subscript_name_1;
            tmp_mvar_value_4 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_sys);

            if (unlikely(tmp_mvar_value_4 == NULL)) {
                tmp_mvar_value_4 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_sys);
            }

            if (tmp_mvar_value_4 == NULL) {

                exception_type = PyExc_NameError;
                Py_INCREF(exception_type);
                exception_value = UNSTREAM_STRING(&constant_bin[ 25 ], 25, 0);
                exception_tb = NULL;

                exception_lineno = 8;

                goto frame_exception_exit_1;
            }

            tmp_source_name_2 = tmp_mvar_value_4;
            tmp_subscribed_name_1 = LOOKUP_ATTRIBUTE(tmp_source_name_2, const_str_plain_argv);
            if (tmp_subscribed_name_1 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 8;

                goto frame_exception_exit_1;
            }
            tmp_subscript_name_1 = const_int_pos_1;
            tmp_assign_source_6 = LOOKUP_SUBSCRIPT_CONST(tmp_subscribed_name_1, tmp_subscript_name_1, 1);
            Py_DECREF(tmp_subscribed_name_1);
            if (tmp_assign_source_6 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 8;

                goto frame_exception_exit_1;
            }
            UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_filename, tmp_assign_source_6);
        }
        branch_end_1:;
    }
    {
        PyObject *tmp_assign_source_7;
        PyObject *tmp_called_name_3;
        PyObject *tmp_mvar_value_5;
        PyObject *tmp_args_element_name_2;
        PyObject *tmp_mvar_value_6;
        PyObject *tmp_args_element_name_3;
        tmp_mvar_value_5 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_open);

        if (unlikely(tmp_mvar_value_5 == NULL)) {
            tmp_mvar_value_5 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_open);
        }

        if (tmp_mvar_value_5 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 77 ], 26, 0);
            exception_tb = NULL;

            exception_lineno = 10;

            goto frame_exception_exit_1;
        }

        tmp_called_name_3 = tmp_mvar_value_5;
        tmp_mvar_value_6 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_filename);

        if (unlikely(tmp_mvar_value_6 == NULL)) {
            tmp_mvar_value_6 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_filename);
        }

        CHECK_OBJECT(tmp_mvar_value_6);
        tmp_args_element_name_2 = tmp_mvar_value_6;
        tmp_args_element_name_3 = const_str_plain_rb;
        frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 10;
        {
            PyObject *call_args[] = {tmp_args_element_name_2, tmp_args_element_name_3};
            tmp_assign_source_7 = CALL_FUNCTION_WITH_ARGS2(tmp_called_name_3, call_args);
        }

        if (tmp_assign_source_7 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 10;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_f, tmp_assign_source_7);
    }
    {
        PyObject *tmp_assign_source_8;
        PyObject *tmp_called_instance_1;
        PyObject *tmp_mvar_value_7;
        tmp_mvar_value_7 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_f);

        if (unlikely(tmp_mvar_value_7 == NULL)) {
            tmp_mvar_value_7 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_f);
        }

        CHECK_OBJECT(tmp_mvar_value_7);
        tmp_called_instance_1 = tmp_mvar_value_7;
        frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 11;
        tmp_assign_source_8 = CALL_METHOD_NO_ARGS(tmp_called_instance_1, const_str_plain_read);
        if (tmp_assign_source_8 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 11;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_cnt, tmp_assign_source_8);
    }
    {
        PyObject *tmp_called_instance_2;
        PyObject *tmp_mvar_value_8;
        PyObject *tmp_call_result_1;
        tmp_mvar_value_8 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_f);

        if (unlikely(tmp_mvar_value_8 == NULL)) {
            tmp_mvar_value_8 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_f);
        }

        if (tmp_mvar_value_8 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 103 ], 23, 0);
            exception_tb = NULL;

            exception_lineno = 12;

            goto frame_exception_exit_1;
        }

        tmp_called_instance_2 = tmp_mvar_value_8;
        frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 12;
        tmp_call_result_1 = CALL_METHOD_NO_ARGS(tmp_called_instance_2, const_str_plain_close);
        if (tmp_call_result_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 12;

            goto frame_exception_exit_1;
        }
        Py_DECREF(tmp_call_result_1);
    }
    {
        PyObject *tmp_assign_source_9;
        Py_ssize_t tmp_sliceslicedel_index_lower_1;
        Py_ssize_t tmp_slice_index_upper_1;
        PyObject *tmp_slice_source_1;
        PyObject *tmp_mvar_value_9;
        tmp_sliceslicedel_index_lower_1 = 0;
        tmp_slice_index_upper_1 = 3;
        tmp_mvar_value_9 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_cnt);

        if (unlikely(tmp_mvar_value_9 == NULL)) {
            tmp_mvar_value_9 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_cnt);
        }

        if (tmp_mvar_value_9 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 126 ], 25, 0);
            exception_tb = NULL;

            exception_lineno = 13;

            goto frame_exception_exit_1;
        }

        tmp_slice_source_1 = tmp_mvar_value_9;
        tmp_assign_source_9 = LOOKUP_INDEX_SLICE(tmp_slice_source_1, tmp_sliceslicedel_index_lower_1, tmp_slice_index_upper_1);
        if (tmp_assign_source_9 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 13;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_strength, tmp_assign_source_9);
    }
    {
        PyObject *tmp_assign_source_10;
        Py_ssize_t tmp_sliceslicedel_index_lower_2;
        Py_ssize_t tmp_slice_index_upper_2;
        PyObject *tmp_slice_source_2;
        PyObject *tmp_mvar_value_10;
        tmp_sliceslicedel_index_lower_2 = 3;
        tmp_slice_index_upper_2 = PY_SSIZE_T_MAX;
        tmp_mvar_value_10 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_cnt);

        if (unlikely(tmp_mvar_value_10 == NULL)) {
            tmp_mvar_value_10 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_cnt);
        }

        if (tmp_mvar_value_10 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 126 ], 25, 0);
            exception_tb = NULL;

            exception_lineno = 14;

            goto frame_exception_exit_1;
        }

        tmp_slice_source_2 = tmp_mvar_value_10;
        tmp_assign_source_10 = LOOKUP_INDEX_SLICE(tmp_slice_source_2, tmp_sliceslicedel_index_lower_2, tmp_slice_index_upper_2);
        if (tmp_assign_source_10 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 14;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_cnt, tmp_assign_source_10);
    }
    {
        PyObject *tmp_assign_source_11;
        Py_ssize_t tmp_sliceslicedel_index_lower_3;
        Py_ssize_t tmp_slice_index_upper_3;
        PyObject *tmp_slice_source_3;
        PyObject *tmp_mvar_value_11;
        tmp_sliceslicedel_index_lower_3 = 0;
        tmp_slice_index_upper_3 = 4;
        tmp_mvar_value_11 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_cnt);

        if (unlikely(tmp_mvar_value_11 == NULL)) {
            tmp_mvar_value_11 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_cnt);
        }

        CHECK_OBJECT(tmp_mvar_value_11);
        tmp_slice_source_3 = tmp_mvar_value_11;
        tmp_assign_source_11 = LOOKUP_INDEX_SLICE(tmp_slice_source_3, tmp_sliceslicedel_index_lower_3, tmp_slice_index_upper_3);
        if (tmp_assign_source_11 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 15;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_magic_cnt, tmp_assign_source_11);
    }
    {
        PyObject *tmp_assign_source_12;
        tmp_assign_source_12 = const_str_digest_7362b9a47180204a87d7e3a16823d69f;
        UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_pswchars, tmp_assign_source_12);
    }
    {
        nuitka_bool tmp_condition_result_2;
        PyObject *tmp_compexpr_left_2;
        PyObject *tmp_compexpr_right_2;
        PyObject *tmp_mvar_value_12;
        tmp_mvar_value_12 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_strength);

        if (unlikely(tmp_mvar_value_12 == NULL)) {
            tmp_mvar_value_12 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_psw_strength);
        }

        CHECK_OBJECT(tmp_mvar_value_12);
        tmp_compexpr_left_2 = tmp_mvar_value_12;
        tmp_compexpr_right_2 = const_str_plain_HIG;
        tmp_res = RICH_COMPARE_BOOL_EQ_OBJECT_OBJECT_NORECURSE(tmp_compexpr_left_2, tmp_compexpr_right_2);
        if (tmp_res == -1) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 19;

            goto frame_exception_exit_1;
        }
        tmp_condition_result_2 = (tmp_res != 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
        if (tmp_condition_result_2 == NUITKA_BOOL_TRUE) {
            goto branch_yes_2;
        } else {
            goto branch_no_2;
        }
        branch_yes_2:;
        {
            PyObject *tmp_assign_source_13;
            tmp_assign_source_13 = const_int_pos_7;
            UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_min_strength, tmp_assign_source_13);
        }
        {
            PyObject *tmp_assign_source_14;
            tmp_assign_source_14 = const_int_pos_20;
            UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_max_strength, tmp_assign_source_14);
        }
        tmp_print_value = const_str_digest_2763934b8069096d2af525dfc5df92fe;
        tmp_result = PRINT_ITEM(tmp_print_value);
        if (tmp_result == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 22;

            goto frame_exception_exit_1;
        }
        if (PRINT_NEW_LINE() == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 22;

            goto frame_exception_exit_1;
        }
        goto branch_end_2;
        branch_no_2:;
        {
            nuitka_bool tmp_condition_result_3;
            PyObject *tmp_compexpr_left_3;
            PyObject *tmp_compexpr_right_3;
            PyObject *tmp_mvar_value_13;
            tmp_mvar_value_13 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_strength);

            if (unlikely(tmp_mvar_value_13 == NULL)) {
                tmp_mvar_value_13 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_psw_strength);
            }

            if (tmp_mvar_value_13 == NULL) {

                exception_type = PyExc_NameError;
                Py_INCREF(exception_type);
                exception_value = UNSTREAM_STRING(&constant_bin[ 151 ], 34, 0);
                exception_tb = NULL;

                exception_lineno = 23;

                goto frame_exception_exit_1;
            }

            tmp_compexpr_left_3 = tmp_mvar_value_13;
            tmp_compexpr_right_3 = const_str_plain_MED;
            tmp_res = RICH_COMPARE_BOOL_EQ_OBJECT_OBJECT_NORECURSE(tmp_compexpr_left_3, tmp_compexpr_right_3);
            if (tmp_res == -1) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 23;

                goto frame_exception_exit_1;
            }
            tmp_condition_result_3 = (tmp_res != 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
            if (tmp_condition_result_3 == NUITKA_BOOL_TRUE) {
                goto branch_yes_3;
            } else {
                goto branch_no_3;
            }
            branch_yes_3:;
            {
                PyObject *tmp_assign_source_15;
                tmp_assign_source_15 = const_int_pos_5;
                UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_min_strength, tmp_assign_source_15);
            }
            {
                PyObject *tmp_assign_source_16;
                tmp_assign_source_16 = const_int_pos_6;
                UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_max_strength, tmp_assign_source_16);
            }
            tmp_print_value = const_str_digest_3fa1e2f311007397326c4d971b118c69;
            tmp_result = PRINT_ITEM(tmp_print_value);
            if (tmp_result == false) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 26;

                goto frame_exception_exit_1;
            }
            if (PRINT_NEW_LINE() == false) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 26;

                goto frame_exception_exit_1;
            }
            goto branch_end_3;
            branch_no_3:;
            {
                PyObject *tmp_assign_source_17;
                tmp_assign_source_17 = const_int_pos_1;
                UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_min_strength, tmp_assign_source_17);
            }
            {
                PyObject *tmp_assign_source_18;
                tmp_assign_source_18 = const_int_pos_4;
                UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_max_strength, tmp_assign_source_18);
            }
            tmp_print_value = const_str_digest_1c866ea462750c72e2bf4ed1feb7001c;
            tmp_result = PRINT_ITEM(tmp_print_value);
            if (tmp_result == false) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 30;

                goto frame_exception_exit_1;
            }
            if (PRINT_NEW_LINE() == false) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 30;

                goto frame_exception_exit_1;
            }
            branch_end_3:;
        }
        branch_end_2:;
    }
    {
        PyObject *tmp_assign_source_19;
        tmp_assign_source_19 = const_int_pos_2;
        UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_version, tmp_assign_source_19);
    }
    {
        PyObject *tmp_assign_source_20;
        PyObject *tmp_called_name_4;
        PyObject *tmp_mvar_value_14;
        PyObject *tmp_args_element_name_4;
        tmp_mvar_value_14 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_bytearray);

        if (unlikely(tmp_mvar_value_14 == NULL)) {
            tmp_mvar_value_14 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_bytearray);
        }

        if (tmp_mvar_value_14 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 185 ], 31, 0);
            exception_tb = NULL;

            exception_lineno = 34;

            goto frame_exception_exit_1;
        }

        tmp_called_name_4 = tmp_mvar_value_14;
        // Tried code:
        {
            PyObject *tmp_assign_source_21;
            PyObject *tmp_iter_arg_1;
            PyObject *tmp_called_name_5;
            PyObject *tmp_mvar_value_15;
            tmp_mvar_value_15 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_range);

            if (unlikely(tmp_mvar_value_15 == NULL)) {
                tmp_mvar_value_15 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_range);
            }

            if (tmp_mvar_value_15 == NULL) {

                exception_type = PyExc_NameError;
                Py_INCREF(exception_type);
                exception_value = UNSTREAM_STRING(&constant_bin[ 216 ], 27, 0);
                exception_tb = NULL;

                exception_lineno = 34;

                goto try_except_handler_1;
            }

            tmp_called_name_5 = tmp_mvar_value_15;
            frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 34;
            tmp_iter_arg_1 = CALL_FUNCTION_WITH_ARGS1(tmp_called_name_5, &PyTuple_GET_ITEM(const_tuple_int_pos_256_tuple, 0));

            if (tmp_iter_arg_1 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 34;

                goto try_except_handler_1;
            }
            tmp_assign_source_21 = MAKE_ITERATOR(tmp_iter_arg_1);
            Py_DECREF(tmp_iter_arg_1);
            if (tmp_assign_source_21 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 34;

                goto try_except_handler_1;
            }
            assert(tmp_list_contraction_1__$0 == NULL);
            tmp_list_contraction_1__$0 = tmp_assign_source_21;
        }
        {
            PyObject *tmp_assign_source_22;
            tmp_assign_source_22 = PyList_New(0);
            assert(tmp_list_contraction_1__contraction_result == NULL);
            tmp_list_contraction_1__contraction_result = tmp_assign_source_22;
        }
        loop_start_1:;
        {
            PyObject *tmp_next_source_1;
            PyObject *tmp_assign_source_23;
            CHECK_OBJECT(tmp_list_contraction_1__$0);
            tmp_next_source_1 = tmp_list_contraction_1__$0;
            tmp_assign_source_23 = ITERATOR_NEXT(tmp_next_source_1);
            if (tmp_assign_source_23 == NULL) {
                if (CHECK_AND_CLEAR_STOP_ITERATION_OCCURRED()) {

                    goto loop_end_1;
                } else {

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);

                    exception_lineno = 34;
                    goto try_except_handler_1;
                }
            }

            {
                PyObject *old = tmp_list_contraction_1__iter_value_0;
                tmp_list_contraction_1__iter_value_0 = tmp_assign_source_23;
                Py_XDECREF(old);
            }

        }
        {
            PyObject *tmp_assign_source_24;
            CHECK_OBJECT(tmp_list_contraction_1__iter_value_0);
            tmp_assign_source_24 = tmp_list_contraction_1__iter_value_0;
            UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_i, tmp_assign_source_24);
        }
        {
            PyObject *tmp_append_list_1;
            PyObject *tmp_append_value_1;
            PyObject *tmp_mvar_value_16;
            CHECK_OBJECT(tmp_list_contraction_1__contraction_result);
            tmp_append_list_1 = tmp_list_contraction_1__contraction_result;
            tmp_mvar_value_16 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_i);

            if (unlikely(tmp_mvar_value_16 == NULL)) {
                tmp_mvar_value_16 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_i);
            }

            CHECK_OBJECT(tmp_mvar_value_16);
            tmp_append_value_1 = tmp_mvar_value_16;
            assert(PyList_Check(tmp_append_list_1));
            tmp_res = PyList_Append(tmp_append_list_1, tmp_append_value_1);
            if (tmp_res == -1) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 34;

                goto try_except_handler_1;
            }
        }
        if (CONSIDER_THREADING() == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_1;
        }
        goto loop_start_1;
        loop_end_1:;
        CHECK_OBJECT(tmp_list_contraction_1__contraction_result);
        tmp_args_element_name_4 = tmp_list_contraction_1__contraction_result;
        Py_INCREF(tmp_args_element_name_4);
        goto try_return_handler_1;
        // tried codes exits in all cases
        NUITKA_CANNOT_GET_HERE(__main__);
        return NULL;
        // Return handler code:
        try_return_handler_1:;
        CHECK_OBJECT((PyObject *)tmp_list_contraction_1__$0);
        Py_DECREF(tmp_list_contraction_1__$0);
        tmp_list_contraction_1__$0 = NULL;

        CHECK_OBJECT((PyObject *)tmp_list_contraction_1__contraction_result);
        Py_DECREF(tmp_list_contraction_1__contraction_result);
        tmp_list_contraction_1__contraction_result = NULL;

        Py_XDECREF(tmp_list_contraction_1__iter_value_0);
        tmp_list_contraction_1__iter_value_0 = NULL;

        goto outline_result_1;
        // Exception handler code:
        try_except_handler_1:;
        exception_keeper_type_1 = exception_type;
        exception_keeper_value_1 = exception_value;
        exception_keeper_tb_1 = exception_tb;
        exception_keeper_lineno_1 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        Py_XDECREF(tmp_list_contraction_1__$0);
        tmp_list_contraction_1__$0 = NULL;

        Py_XDECREF(tmp_list_contraction_1__contraction_result);
        tmp_list_contraction_1__contraction_result = NULL;

        Py_XDECREF(tmp_list_contraction_1__iter_value_0);
        tmp_list_contraction_1__iter_value_0 = NULL;

        // Re-raise.
        exception_type = exception_keeper_type_1;
        exception_value = exception_keeper_value_1;
        exception_tb = exception_keeper_tb_1;
        exception_lineno = exception_keeper_lineno_1;

        goto frame_exception_exit_1;
        // End of try:
        // Return statement must have exited already.
        NUITKA_CANNOT_GET_HERE(__main__);
        return NULL;
        outline_result_1:;
        frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 34;
        tmp_assign_source_20 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_4, tmp_args_element_name_4);
        Py_DECREF(tmp_args_element_name_4);
        if (tmp_assign_source_20 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_b, tmp_assign_source_20);
    }
    {
        PyObject *tmp_assign_source_25;
        PyObject *tmp_mvar_value_17;
        tmp_mvar_value_17 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_False);

        if (unlikely(tmp_mvar_value_17 == NULL)) {
            tmp_mvar_value_17 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_False);
        }

        if (tmp_mvar_value_17 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 243 ], 27, 0);
            exception_tb = NULL;

            exception_lineno = 35;

            goto frame_exception_exit_1;
        }

        tmp_assign_source_25 = tmp_mvar_value_17;
        UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_fnd, tmp_assign_source_25);
    }
    {
        PyObject *tmp_assign_source_26;
        tmp_assign_source_26 = const_int_0;
        UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_count, tmp_assign_source_26);
    }
    {
        nuitka_bool tmp_condition_result_4;
        PyObject *tmp_compexpr_left_4;
        PyObject *tmp_compexpr_right_4;
        PyObject *tmp_mvar_value_18;
        tmp_mvar_value_18 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_version);

        if (unlikely(tmp_mvar_value_18 == NULL)) {
            tmp_mvar_value_18 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_version);
        }

        if (tmp_mvar_value_18 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 270 ], 29, 0);
            exception_tb = NULL;

            exception_lineno = 37;

            goto frame_exception_exit_1;
        }

        tmp_compexpr_left_4 = tmp_mvar_value_18;
        tmp_compexpr_right_4 = const_int_pos_2;
        tmp_res = RICH_COMPARE_BOOL_EQ_OBJECT_OBJECT_NORECURSE(tmp_compexpr_left_4, tmp_compexpr_right_4);
        if (tmp_res == -1) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto frame_exception_exit_1;
        }
        tmp_condition_result_4 = (tmp_res != 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
        if (tmp_condition_result_4 == NUITKA_BOOL_TRUE) {
            goto branch_yes_4;
        } else {
            goto branch_no_4;
        }
        branch_yes_4:;
        {
            nuitka_bool tmp_condition_result_5;
            PyObject *tmp_operand_name_1;
            PyObject *tmp_mvar_value_19;
            tmp_mvar_value_19 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_fnd);

            if (unlikely(tmp_mvar_value_19 == NULL)) {
                tmp_mvar_value_19 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_psw_fnd);
            }

            if (tmp_mvar_value_19 == NULL) {

                exception_type = PyExc_NameError;
                Py_INCREF(exception_type);
                exception_value = UNSTREAM_STRING(&constant_bin[ 299 ], 29, 0);
                exception_tb = NULL;

                exception_lineno = 38;

                goto frame_exception_exit_1;
            }

            tmp_operand_name_1 = tmp_mvar_value_19;
            tmp_res = CHECK_IF_TRUE(tmp_operand_name_1);
            if (tmp_res == -1) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 38;

                goto frame_exception_exit_1;
            }
            tmp_condition_result_5 = (tmp_res == 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
            if (tmp_condition_result_5 == NUITKA_BOOL_TRUE) {
                goto branch_yes_5;
            } else {
                goto branch_no_5;
            }
            branch_yes_5:;
            {
                PyObject *tmp_assign_source_27;
                PyObject *tmp_iter_arg_2;
                PyObject *tmp_called_name_6;
                PyObject *tmp_mvar_value_20;
                tmp_mvar_value_20 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_range);

                if (unlikely(tmp_mvar_value_20 == NULL)) {
                    tmp_mvar_value_20 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_range);
                }

                if (tmp_mvar_value_20 == NULL) {

                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 216 ], 27, 0);
                    exception_tb = NULL;

                    exception_lineno = 39;

                    goto frame_exception_exit_1;
                }

                tmp_called_name_6 = tmp_mvar_value_20;
                frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 39;
                tmp_iter_arg_2 = CALL_FUNCTION_WITH_ARGS1(tmp_called_name_6, &PyTuple_GET_ITEM(const_tuple_int_pos_16777216_tuple, 0));

                if (tmp_iter_arg_2 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 39;

                    goto frame_exception_exit_1;
                }
                tmp_assign_source_27 = MAKE_ITERATOR(tmp_iter_arg_2);
                Py_DECREF(tmp_iter_arg_2);
                if (tmp_assign_source_27 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 39;

                    goto frame_exception_exit_1;
                }
                assert(tmp_for_loop_1__for_iterator == NULL);
                tmp_for_loop_1__for_iterator = tmp_assign_source_27;
            }
            // Tried code:
            loop_start_2:;
            {
                PyObject *tmp_next_source_2;
                PyObject *tmp_assign_source_28;
                CHECK_OBJECT(tmp_for_loop_1__for_iterator);
                tmp_next_source_2 = tmp_for_loop_1__for_iterator;
                tmp_assign_source_28 = ITERATOR_NEXT(tmp_next_source_2);
                if (tmp_assign_source_28 == NULL) {
                    if (CHECK_AND_CLEAR_STOP_ITERATION_OCCURRED()) {

                        goto loop_end_2;
                    } else {

                        FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);

                        exception_lineno = 39;
                        goto try_except_handler_2;
                    }
                }

                {
                    PyObject *old = tmp_for_loop_1__iter_value;
                    tmp_for_loop_1__iter_value = tmp_assign_source_28;
                    Py_XDECREF(old);
                }

            }
            {
                PyObject *tmp_assign_source_29;
                CHECK_OBJECT(tmp_for_loop_1__iter_value);
                tmp_assign_source_29 = tmp_for_loop_1__iter_value;
                UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_cand, tmp_assign_source_29);
            }
            {
                PyObject *tmp_assign_source_30;
                PyObject *tmp_left_name_1;
                PyObject *tmp_mvar_value_21;
                PyObject *tmp_right_name_1;
                tmp_mvar_value_21 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_cand);

                if (unlikely(tmp_mvar_value_21 == NULL)) {
                    tmp_mvar_value_21 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_psw_cand);
                }

                CHECK_OBJECT(tmp_mvar_value_21);
                tmp_left_name_1 = tmp_mvar_value_21;
                tmp_right_name_1 = const_int_pos_3;
                tmp_assign_source_30 = BINARY_OPERATION_LSHIFT_OBJECT_INT(tmp_left_name_1, tmp_right_name_1);
                if (tmp_assign_source_30 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 40;

                    goto try_except_handler_2;
                }
                UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_cand, tmp_assign_source_30);
            }
            {
                PyObject *tmp_assign_source_31;
                PyObject *tmp_left_name_2;
                PyObject *tmp_mvar_value_22;
                PyObject *tmp_right_name_2;
                tmp_mvar_value_22 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_count);

                if (unlikely(tmp_mvar_value_22 == NULL)) {
                    tmp_mvar_value_22 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_count);
                }

                if (tmp_mvar_value_22 == NULL) {

                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 328 ], 27, 0);
                    exception_tb = NULL;

                    exception_lineno = 41;

                    goto try_except_handler_2;
                }

                tmp_left_name_2 = tmp_mvar_value_22;
                tmp_right_name_2 = const_int_pos_1;
                tmp_inplace_orig = tmp_left_name_2;
                tmp_result = BINARY_OPERATION_ADD_OBJECT_INT_INPLACE(&tmp_left_name_2, tmp_right_name_2);
                if (tmp_result == false) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 41;

                    goto try_except_handler_2;
                }
                tmp_assign_source_31 = tmp_left_name_2;
                if (tmp_inplace_orig != tmp_assign_source_31) {
                UPDATE_STRING_DICT_INPLACE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_count, tmp_assign_source_31);
                }
            }
            {
                nuitka_bool tmp_condition_result_6;
                PyObject *tmp_compexpr_left_5;
                PyObject *tmp_compexpr_right_5;
                PyObject *tmp_left_name_3;
                PyObject *tmp_mvar_value_23;
                PyObject *tmp_right_name_3;
                tmp_mvar_value_23 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_count);

                if (unlikely(tmp_mvar_value_23 == NULL)) {
                    tmp_mvar_value_23 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_count);
                }

                CHECK_OBJECT(tmp_mvar_value_23);
                tmp_left_name_3 = tmp_mvar_value_23;
                tmp_right_name_3 = const_int_pos_10000;
                tmp_compexpr_left_5 = BINARY_OPERATION_MOD_OBJECT_INT(tmp_left_name_3, tmp_right_name_3);
                if (tmp_compexpr_left_5 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 42;

                    goto try_except_handler_2;
                }
                tmp_compexpr_right_5 = const_int_0;
                tmp_res = RICH_COMPARE_BOOL_EQ_OBJECT_OBJECT_NORECURSE(tmp_compexpr_left_5, tmp_compexpr_right_5);
                Py_DECREF(tmp_compexpr_left_5);
                if (tmp_res == -1) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 42;

                    goto try_except_handler_2;
                }
                tmp_condition_result_6 = (tmp_res != 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
                if (tmp_condition_result_6 == NUITKA_BOOL_TRUE) {
                    goto branch_yes_6;
                } else {
                    goto branch_no_6;
                }
                branch_yes_6:;
                {
                    PyObject *tmp_mvar_value_24;
                    tmp_mvar_value_24 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_count);

                    if (unlikely(tmp_mvar_value_24 == NULL)) {
                        tmp_mvar_value_24 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_count);
                    }

                    if (tmp_mvar_value_24 == NULL) {

                        exception_type = PyExc_NameError;
                        Py_INCREF(exception_type);
                        exception_value = UNSTREAM_STRING(&constant_bin[ 328 ], 27, 0);
                        exception_tb = NULL;

                        exception_lineno = 43;

                        goto try_except_handler_2;
                    }

                    tmp_print_value = tmp_mvar_value_24;
                    tmp_result = PRINT_ITEM(tmp_print_value);
                    if (tmp_result == false) {
                        assert(ERROR_OCCURRED());

                        FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                        exception_lineno = 43;

                        goto try_except_handler_2;
                    }
                }
                if (PRINT_NEW_LINE() == false) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 43;

                    goto try_except_handler_2;
                }
                branch_no_6:;
            }
            {
                PyObject *tmp_assign_source_32;
                PyObject *tmp_called_name_7;
                PyObject *tmp_mvar_value_25;
                PyObject *tmp_args_name_1;
                PyObject *tmp_tuple_element_1;
                PyObject *tmp_mvar_value_26;
                PyObject *tmp_mvar_value_27;
                PyObject *tmp_kw_name_1;
                tmp_mvar_value_25 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_decrypt);

                if (unlikely(tmp_mvar_value_25 == NULL)) {
                    tmp_mvar_value_25 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_decrypt);
                }

                if (tmp_mvar_value_25 == NULL) {

                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 355 ], 29, 0);
                    exception_tb = NULL;

                    exception_lineno = 44;

                    goto try_except_handler_2;
                }

                tmp_called_name_7 = tmp_mvar_value_25;
                tmp_mvar_value_26 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_magic_cnt);

                if (unlikely(tmp_mvar_value_26 == NULL)) {
                    tmp_mvar_value_26 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_magic_cnt);
                }

                if (tmp_mvar_value_26 == NULL) {

                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 384 ], 31, 0);
                    exception_tb = NULL;

                    exception_lineno = 44;

                    goto try_except_handler_2;
                }

                tmp_tuple_element_1 = tmp_mvar_value_26;
                tmp_args_name_1 = PyTuple_New(2);
                Py_INCREF(tmp_tuple_element_1);
                PyTuple_SET_ITEM(tmp_args_name_1, 0, tmp_tuple_element_1);
                tmp_mvar_value_27 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_cand);

                if (unlikely(tmp_mvar_value_27 == NULL)) {
                    tmp_mvar_value_27 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_psw_cand);
                }

                if (tmp_mvar_value_27 == NULL) {
                    Py_DECREF(tmp_args_name_1);
                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 415 ], 30, 0);
                    exception_tb = NULL;

                    exception_lineno = 44;

                    goto try_except_handler_2;
                }

                tmp_tuple_element_1 = tmp_mvar_value_27;
                Py_INCREF(tmp_tuple_element_1);
                PyTuple_SET_ITEM(tmp_args_name_1, 1, tmp_tuple_element_1);
                tmp_kw_name_1 = PyDict_Copy(const_dict_b2cc954541260c68ff55aca1b97f76b4);
                frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 44;
                tmp_assign_source_32 = CALL_FUNCTION(tmp_called_name_7, tmp_args_name_1, tmp_kw_name_1);
                Py_DECREF(tmp_args_name_1);
                Py_DECREF(tmp_kw_name_1);
                if (tmp_assign_source_32 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 44;

                    goto try_except_handler_2;
                }
                UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_magic_dec, tmp_assign_source_32);
            }
            {
                nuitka_bool tmp_condition_result_7;
                PyObject *tmp_compexpr_left_6;
                PyObject *tmp_compexpr_right_6;
                PyObject *tmp_mvar_value_28;
                PyObject *tmp_mvar_value_29;
                tmp_mvar_value_28 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_magic_dec);

                if (unlikely(tmp_mvar_value_28 == NULL)) {
                    tmp_mvar_value_28 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_magic_dec);
                }

                CHECK_OBJECT(tmp_mvar_value_28);
                tmp_compexpr_left_6 = tmp_mvar_value_28;
                tmp_mvar_value_29 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_MAGIC);

                if (unlikely(tmp_mvar_value_29 == NULL)) {
                    tmp_mvar_value_29 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_MAGIC);
                }

                if (tmp_mvar_value_29 == NULL) {

                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 445 ], 27, 0);
                    exception_tb = NULL;

                    exception_lineno = 45;

                    goto try_except_handler_2;
                }

                tmp_compexpr_right_6 = tmp_mvar_value_29;
                tmp_res = RICH_COMPARE_BOOL_EQ_OBJECT_OBJECT_NORECURSE(tmp_compexpr_left_6, tmp_compexpr_right_6);
                if (tmp_res == -1) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 45;

                    goto try_except_handler_2;
                }
                tmp_condition_result_7 = (tmp_res != 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
                if (tmp_condition_result_7 == NUITKA_BOOL_TRUE) {
                    goto branch_yes_7;
                } else {
                    goto branch_no_7;
                }
                branch_yes_7:;
                {
                    PyObject *tmp_assign_source_33;
                    PyObject *tmp_mvar_value_30;
                    tmp_mvar_value_30 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_True);

                    if (unlikely(tmp_mvar_value_30 == NULL)) {
                        tmp_mvar_value_30 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_True);
                    }

                    if (tmp_mvar_value_30 == NULL) {

                        exception_type = PyExc_NameError;
                        Py_INCREF(exception_type);
                        exception_value = UNSTREAM_STRING(&constant_bin[ 472 ], 26, 0);
                        exception_tb = NULL;

                        exception_lineno = 46;

                        goto try_except_handler_2;
                    }

                    tmp_assign_source_33 = tmp_mvar_value_30;
                    UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_fnd, tmp_assign_source_33);
                }
                {
                    PyObject *tmp_left_name_4;
                    PyObject *tmp_right_name_4;
                    PyObject *tmp_mvar_value_31;
                    tmp_left_name_4 = const_str_digest_3d86b0fa60a546d30bce814f02c93d46;
                    tmp_mvar_value_31 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_cand);

                    if (unlikely(tmp_mvar_value_31 == NULL)) {
                        tmp_mvar_value_31 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_psw_cand);
                    }

                    if (tmp_mvar_value_31 == NULL) {

                        exception_type = PyExc_NameError;
                        Py_INCREF(exception_type);
                        exception_value = UNSTREAM_STRING(&constant_bin[ 415 ], 30, 0);
                        exception_tb = NULL;

                        exception_lineno = 47;

                        goto try_except_handler_2;
                    }

                    tmp_right_name_4 = tmp_mvar_value_31;
                    tmp_print_value = BINARY_OPERATION_MOD_STR_OBJECT(tmp_left_name_4, tmp_right_name_4);
                    if (tmp_print_value == NULL) {
                        assert(ERROR_OCCURRED());

                        FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                        exception_lineno = 47;

                        goto try_except_handler_2;
                    }
                    tmp_result = PRINT_ITEM(tmp_print_value);
                    Py_DECREF(tmp_print_value);
                    if (tmp_result == false) {
                        assert(ERROR_OCCURRED());

                        FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                        exception_lineno = 47;

                        goto try_except_handler_2;
                    }
                }
                if (PRINT_NEW_LINE() == false) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 47;

                    goto try_except_handler_2;
                }
                goto loop_end_2;
                branch_no_7:;
            }
            if (CONSIDER_THREADING() == false) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 39;

                goto try_except_handler_2;
            }
            goto loop_start_2;
            loop_end_2:;
            goto try_end_1;
            // Exception handler code:
            try_except_handler_2:;
            exception_keeper_type_2 = exception_type;
            exception_keeper_value_2 = exception_value;
            exception_keeper_tb_2 = exception_tb;
            exception_keeper_lineno_2 = exception_lineno;
            exception_type = NULL;
            exception_value = NULL;
            exception_tb = NULL;
            exception_lineno = 0;

            Py_XDECREF(tmp_for_loop_1__iter_value);
            tmp_for_loop_1__iter_value = NULL;

            CHECK_OBJECT((PyObject *)tmp_for_loop_1__for_iterator);
            Py_DECREF(tmp_for_loop_1__for_iterator);
            tmp_for_loop_1__for_iterator = NULL;

            // Re-raise.
            exception_type = exception_keeper_type_2;
            exception_value = exception_keeper_value_2;
            exception_tb = exception_keeper_tb_2;
            exception_lineno = exception_keeper_lineno_2;

            goto frame_exception_exit_1;
            // End of try:
            try_end_1:;
            Py_XDECREF(tmp_for_loop_1__iter_value);
            tmp_for_loop_1__iter_value = NULL;

            CHECK_OBJECT((PyObject *)tmp_for_loop_1__for_iterator);
            Py_DECREF(tmp_for_loop_1__for_iterator);
            tmp_for_loop_1__for_iterator = NULL;

            branch_no_5:;
        }
        goto branch_end_4;
        branch_no_4:;
        {
            PyObject *tmp_assign_source_34;
            PyObject *tmp_iter_arg_3;
            PyObject *tmp_called_name_8;
            PyObject *tmp_mvar_value_32;
            PyObject *tmp_args_element_name_5;
            PyObject *tmp_mvar_value_33;
            PyObject *tmp_args_element_name_6;
            PyObject *tmp_left_name_5;
            PyObject *tmp_mvar_value_34;
            PyObject *tmp_right_name_5;
            tmp_mvar_value_32 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_range);

            if (unlikely(tmp_mvar_value_32 == NULL)) {
                tmp_mvar_value_32 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_range);
            }

            if (tmp_mvar_value_32 == NULL) {

                exception_type = PyExc_NameError;
                Py_INCREF(exception_type);
                exception_value = UNSTREAM_STRING(&constant_bin[ 216 ], 27, 0);
                exception_tb = NULL;

                exception_lineno = 50;

                goto frame_exception_exit_1;
            }

            tmp_called_name_8 = tmp_mvar_value_32;
            tmp_mvar_value_33 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_min_strength);

            if (unlikely(tmp_mvar_value_33 == NULL)) {
                tmp_mvar_value_33 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_min_strength);
            }

            if (tmp_mvar_value_33 == NULL) {

                exception_type = PyExc_NameError;
                Py_INCREF(exception_type);
                exception_value = UNSTREAM_STRING(&constant_bin[ 498 ], 34, 0);
                exception_tb = NULL;

                exception_lineno = 50;

                goto frame_exception_exit_1;
            }

            tmp_args_element_name_5 = tmp_mvar_value_33;
            tmp_mvar_value_34 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_max_strength);

            if (unlikely(tmp_mvar_value_34 == NULL)) {
                tmp_mvar_value_34 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_max_strength);
            }

            if (tmp_mvar_value_34 == NULL) {

                exception_type = PyExc_NameError;
                Py_INCREF(exception_type);
                exception_value = UNSTREAM_STRING(&constant_bin[ 532 ], 34, 0);
                exception_tb = NULL;

                exception_lineno = 50;

                goto frame_exception_exit_1;
            }

            tmp_left_name_5 = tmp_mvar_value_34;
            tmp_right_name_5 = const_int_pos_1;
            tmp_args_element_name_6 = BINARY_OPERATION_ADD_OBJECT_INT(tmp_left_name_5, tmp_right_name_5);
            if (tmp_args_element_name_6 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 50;

                goto frame_exception_exit_1;
            }
            frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 50;
            {
                PyObject *call_args[] = {tmp_args_element_name_5, tmp_args_element_name_6};
                tmp_iter_arg_3 = CALL_FUNCTION_WITH_ARGS2(tmp_called_name_8, call_args);
            }

            Py_DECREF(tmp_args_element_name_6);
            if (tmp_iter_arg_3 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 50;

                goto frame_exception_exit_1;
            }
            tmp_assign_source_34 = MAKE_ITERATOR(tmp_iter_arg_3);
            Py_DECREF(tmp_iter_arg_3);
            if (tmp_assign_source_34 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 50;

                goto frame_exception_exit_1;
            }
            assert(tmp_for_loop_2__for_iterator == NULL);
            tmp_for_loop_2__for_iterator = tmp_assign_source_34;
        }
        // Tried code:
        loop_start_3:;
        {
            PyObject *tmp_next_source_3;
            PyObject *tmp_assign_source_35;
            CHECK_OBJECT(tmp_for_loop_2__for_iterator);
            tmp_next_source_3 = tmp_for_loop_2__for_iterator;
            tmp_assign_source_35 = ITERATOR_NEXT(tmp_next_source_3);
            if (tmp_assign_source_35 == NULL) {
                if (CHECK_AND_CLEAR_STOP_ITERATION_OCCURRED()) {

                    goto loop_end_3;
                } else {

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);

                    exception_lineno = 50;
                    goto try_except_handler_3;
                }
            }

            {
                PyObject *old = tmp_for_loop_2__iter_value;
                tmp_for_loop_2__iter_value = tmp_assign_source_35;
                Py_XDECREF(old);
            }

        }
        {
            PyObject *tmp_assign_source_36;
            CHECK_OBJECT(tmp_for_loop_2__iter_value);
            tmp_assign_source_36 = tmp_for_loop_2__iter_value;
            UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_length, tmp_assign_source_36);
        }
        {
            nuitka_bool tmp_condition_result_8;
            PyObject *tmp_operand_name_2;
            PyObject *tmp_mvar_value_35;
            tmp_mvar_value_35 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_fnd);

            if (unlikely(tmp_mvar_value_35 == NULL)) {
                tmp_mvar_value_35 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_psw_fnd);
            }

            if (tmp_mvar_value_35 == NULL) {

                exception_type = PyExc_NameError;
                Py_INCREF(exception_type);
                exception_value = UNSTREAM_STRING(&constant_bin[ 299 ], 29, 0);
                exception_tb = NULL;

                exception_lineno = 51;

                goto try_except_handler_3;
            }

            tmp_operand_name_2 = tmp_mvar_value_35;
            tmp_res = CHECK_IF_TRUE(tmp_operand_name_2);
            if (tmp_res == -1) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 51;

                goto try_except_handler_3;
            }
            tmp_condition_result_8 = (tmp_res == 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
            if (tmp_condition_result_8 == NUITKA_BOOL_TRUE) {
                goto branch_yes_8;
            } else {
                goto branch_no_8;
            }
            branch_yes_8:;
            {
                PyObject *tmp_left_name_6;
                PyObject *tmp_right_name_6;
                PyObject *tmp_mvar_value_36;
                tmp_left_name_6 = const_str_digest_f6d6cc00f060d6e2f31f38f19b48443c;
                tmp_mvar_value_36 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_length);

                if (unlikely(tmp_mvar_value_36 == NULL)) {
                    tmp_mvar_value_36 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_length);
                }

                if (tmp_mvar_value_36 == NULL) {

                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 566 ], 28, 0);
                    exception_tb = NULL;

                    exception_lineno = 52;

                    goto try_except_handler_3;
                }

                tmp_right_name_6 = tmp_mvar_value_36;
                tmp_print_value = BINARY_OPERATION_MOD_STR_OBJECT(tmp_left_name_6, tmp_right_name_6);
                if (tmp_print_value == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 52;

                    goto try_except_handler_3;
                }
                tmp_result = PRINT_ITEM(tmp_print_value);
                Py_DECREF(tmp_print_value);
                if (tmp_result == false) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 52;

                    goto try_except_handler_3;
                }
            }
            if (PRINT_NEW_LINE() == false) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 52;

                goto try_except_handler_3;
            }
            {
                PyObject *tmp_assign_source_37;
                PyObject *tmp_iter_arg_4;
                PyObject *tmp_called_name_9;
                PyObject *tmp_source_name_3;
                PyObject *tmp_mvar_value_37;
                PyObject *tmp_args_element_name_7;
                PyObject *tmp_mvar_value_38;
                PyObject *tmp_args_element_name_8;
                PyObject *tmp_mvar_value_39;
                tmp_mvar_value_37 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_it);

                if (unlikely(tmp_mvar_value_37 == NULL)) {
                    tmp_mvar_value_37 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_it);
                }

                if (tmp_mvar_value_37 == NULL) {

                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 594 ], 24, 0);
                    exception_tb = NULL;

                    exception_lineno = 53;

                    goto try_except_handler_3;
                }

                tmp_source_name_3 = tmp_mvar_value_37;
                tmp_called_name_9 = LOOKUP_ATTRIBUTE(tmp_source_name_3, const_str_plain_permutations);
                if (tmp_called_name_9 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 53;

                    goto try_except_handler_3;
                }
                tmp_mvar_value_38 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_pswchars);

                if (unlikely(tmp_mvar_value_38 == NULL)) {
                    tmp_mvar_value_38 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_pswchars);
                }

                if (tmp_mvar_value_38 == NULL) {
                    Py_DECREF(tmp_called_name_9);
                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 618 ], 30, 0);
                    exception_tb = NULL;

                    exception_lineno = 53;

                    goto try_except_handler_3;
                }

                tmp_args_element_name_7 = tmp_mvar_value_38;
                tmp_mvar_value_39 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_length);

                if (unlikely(tmp_mvar_value_39 == NULL)) {
                    tmp_mvar_value_39 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_length);
                }

                if (tmp_mvar_value_39 == NULL) {
                    Py_DECREF(tmp_called_name_9);
                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 566 ], 28, 0);
                    exception_tb = NULL;

                    exception_lineno = 53;

                    goto try_except_handler_3;
                }

                tmp_args_element_name_8 = tmp_mvar_value_39;
                frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 53;
                {
                    PyObject *call_args[] = {tmp_args_element_name_7, tmp_args_element_name_8};
                    tmp_iter_arg_4 = CALL_FUNCTION_WITH_ARGS2(tmp_called_name_9, call_args);
                }

                Py_DECREF(tmp_called_name_9);
                if (tmp_iter_arg_4 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 53;

                    goto try_except_handler_3;
                }
                tmp_assign_source_37 = MAKE_ITERATOR(tmp_iter_arg_4);
                Py_DECREF(tmp_iter_arg_4);
                if (tmp_assign_source_37 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 53;

                    goto try_except_handler_3;
                }
                {
                    PyObject *old = tmp_for_loop_3__for_iterator;
                    tmp_for_loop_3__for_iterator = tmp_assign_source_37;
                    Py_XDECREF(old);
                }

            }
            // Tried code:
            loop_start_4:;
            {
                PyObject *tmp_next_source_4;
                PyObject *tmp_assign_source_38;
                CHECK_OBJECT(tmp_for_loop_3__for_iterator);
                tmp_next_source_4 = tmp_for_loop_3__for_iterator;
                tmp_assign_source_38 = ITERATOR_NEXT(tmp_next_source_4);
                if (tmp_assign_source_38 == NULL) {
                    if (CHECK_AND_CLEAR_STOP_ITERATION_OCCURRED()) {

                        goto loop_end_4;
                    } else {

                        FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);

                        exception_lineno = 53;
                        goto try_except_handler_4;
                    }
                }

                {
                    PyObject *old = tmp_for_loop_3__iter_value;
                    tmp_for_loop_3__iter_value = tmp_assign_source_38;
                    Py_XDECREF(old);
                }

            }
            {
                PyObject *tmp_assign_source_39;
                CHECK_OBJECT(tmp_for_loop_3__iter_value);
                tmp_assign_source_39 = tmp_for_loop_3__iter_value;
                UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_per, tmp_assign_source_39);
            }
            {
                PyObject *tmp_assign_source_40;
                PyObject *tmp_called_instance_3;
                PyObject *tmp_args_element_name_9;
                PyObject *tmp_mvar_value_40;
                tmp_called_instance_3 = const_str_empty;
                tmp_mvar_value_40 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_per);

                if (unlikely(tmp_mvar_value_40 == NULL)) {
                    tmp_mvar_value_40 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_per);
                }

                CHECK_OBJECT(tmp_mvar_value_40);
                tmp_args_element_name_9 = tmp_mvar_value_40;
                frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 54;
                {
                    PyObject *call_args[] = {tmp_args_element_name_9};
                    tmp_assign_source_40 = CALL_METHOD_WITH_ARGS1(tmp_called_instance_3, const_str_plain_join, call_args);
                }

                if (tmp_assign_source_40 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 54;

                    goto try_except_handler_4;
                }
                UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_per, tmp_assign_source_40);
            }
            {
                PyObject *tmp_assign_source_41;
                PyObject *tmp_called_name_10;
                PyObject *tmp_mvar_value_41;
                PyObject *tmp_args_element_name_10;
                PyObject *tmp_mvar_value_42;
                PyObject *tmp_args_element_name_11;
                PyObject *tmp_mvar_value_43;
                tmp_mvar_value_41 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_decrypt);

                if (unlikely(tmp_mvar_value_41 == NULL)) {
                    tmp_mvar_value_41 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_decrypt);
                }

                if (tmp_mvar_value_41 == NULL) {

                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 355 ], 29, 0);
                    exception_tb = NULL;

                    exception_lineno = 55;

                    goto try_except_handler_4;
                }

                tmp_called_name_10 = tmp_mvar_value_41;
                tmp_mvar_value_42 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_magic_cnt);

                if (unlikely(tmp_mvar_value_42 == NULL)) {
                    tmp_mvar_value_42 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_magic_cnt);
                }

                if (tmp_mvar_value_42 == NULL) {

                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 384 ], 31, 0);
                    exception_tb = NULL;

                    exception_lineno = 55;

                    goto try_except_handler_4;
                }

                tmp_args_element_name_10 = tmp_mvar_value_42;
                tmp_mvar_value_43 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_per);

                if (unlikely(tmp_mvar_value_43 == NULL)) {
                    tmp_mvar_value_43 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_per);
                }

                CHECK_OBJECT(tmp_mvar_value_43);
                tmp_args_element_name_11 = tmp_mvar_value_43;
                frame_2fed2079e999b99c6812552efed77f38->m_frame.f_lineno = 55;
                {
                    PyObject *call_args[] = {tmp_args_element_name_10, tmp_args_element_name_11};
                    tmp_assign_source_41 = CALL_FUNCTION_WITH_ARGS2(tmp_called_name_10, call_args);
                }

                if (tmp_assign_source_41 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 55;

                    goto try_except_handler_4;
                }
                UPDATE_STRING_DICT1(moduledict___main__, (Nuitka_StringObject *)const_str_plain_magic_dec, tmp_assign_source_41);
            }
            {
                nuitka_bool tmp_condition_result_9;
                PyObject *tmp_compexpr_left_7;
                PyObject *tmp_compexpr_right_7;
                PyObject *tmp_mvar_value_44;
                PyObject *tmp_mvar_value_45;
                tmp_mvar_value_44 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_magic_dec);

                if (unlikely(tmp_mvar_value_44 == NULL)) {
                    tmp_mvar_value_44 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_magic_dec);
                }

                CHECK_OBJECT(tmp_mvar_value_44);
                tmp_compexpr_left_7 = tmp_mvar_value_44;
                tmp_mvar_value_45 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_MAGIC);

                if (unlikely(tmp_mvar_value_45 == NULL)) {
                    tmp_mvar_value_45 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_MAGIC);
                }

                if (tmp_mvar_value_45 == NULL) {

                    exception_type = PyExc_NameError;
                    Py_INCREF(exception_type);
                    exception_value = UNSTREAM_STRING(&constant_bin[ 445 ], 27, 0);
                    exception_tb = NULL;

                    exception_lineno = 56;

                    goto try_except_handler_4;
                }

                tmp_compexpr_right_7 = tmp_mvar_value_45;
                tmp_res = RICH_COMPARE_BOOL_EQ_OBJECT_OBJECT_NORECURSE(tmp_compexpr_left_7, tmp_compexpr_right_7);
                if (tmp_res == -1) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 56;

                    goto try_except_handler_4;
                }
                tmp_condition_result_9 = (tmp_res != 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
                if (tmp_condition_result_9 == NUITKA_BOOL_TRUE) {
                    goto branch_yes_9;
                } else {
                    goto branch_no_9;
                }
                branch_yes_9:;
                {
                    PyObject *tmp_assign_source_42;
                    PyObject *tmp_mvar_value_46;
                    tmp_mvar_value_46 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_True);

                    if (unlikely(tmp_mvar_value_46 == NULL)) {
                        tmp_mvar_value_46 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_True);
                    }

                    if (tmp_mvar_value_46 == NULL) {

                        exception_type = PyExc_NameError;
                        Py_INCREF(exception_type);
                        exception_value = UNSTREAM_STRING(&constant_bin[ 472 ], 26, 0);
                        exception_tb = NULL;

                        exception_lineno = 57;

                        goto try_except_handler_4;
                    }

                    tmp_assign_source_42 = tmp_mvar_value_46;
                    UPDATE_STRING_DICT0(moduledict___main__, (Nuitka_StringObject *)const_str_plain_psw_fnd, tmp_assign_source_42);
                }
                {
                    PyObject *tmp_left_name_7;
                    PyObject *tmp_right_name_7;
                    PyObject *tmp_mvar_value_47;
                    tmp_left_name_7 = const_str_digest_3d86b0fa60a546d30bce814f02c93d46;
                    tmp_mvar_value_47 = GET_STRING_DICT_VALUE(moduledict___main__, (Nuitka_StringObject *)const_str_plain_per);

                    if (unlikely(tmp_mvar_value_47 == NULL)) {
                        tmp_mvar_value_47 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_per);
                    }

                    if (tmp_mvar_value_47 == NULL) {

                        exception_type = PyExc_NameError;
                        Py_INCREF(exception_type);
                        exception_value = UNSTREAM_STRING(&constant_bin[ 648 ], 25, 0);
                        exception_tb = NULL;

                        exception_lineno = 58;

                        goto try_except_handler_4;
                    }

                    tmp_right_name_7 = tmp_mvar_value_47;
                    tmp_print_value = BINARY_OPERATION_MOD_STR_OBJECT(tmp_left_name_7, tmp_right_name_7);
                    if (tmp_print_value == NULL) {
                        assert(ERROR_OCCURRED());

                        FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                        exception_lineno = 58;

                        goto try_except_handler_4;
                    }
                    tmp_result = PRINT_ITEM(tmp_print_value);
                    Py_DECREF(tmp_print_value);
                    if (tmp_result == false) {
                        assert(ERROR_OCCURRED());

                        FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                        exception_lineno = 58;

                        goto try_except_handler_4;
                    }
                }
                if (PRINT_NEW_LINE() == false) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 58;

                    goto try_except_handler_4;
                }
                goto loop_end_4;
                branch_no_9:;
            }
            if (CONSIDER_THREADING() == false) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 53;

                goto try_except_handler_4;
            }
            goto loop_start_4;
            loop_end_4:;
            goto try_end_2;
            // Exception handler code:
            try_except_handler_4:;
            exception_keeper_type_3 = exception_type;
            exception_keeper_value_3 = exception_value;
            exception_keeper_tb_3 = exception_tb;
            exception_keeper_lineno_3 = exception_lineno;
            exception_type = NULL;
            exception_value = NULL;
            exception_tb = NULL;
            exception_lineno = 0;

            Py_XDECREF(tmp_for_loop_3__iter_value);
            tmp_for_loop_3__iter_value = NULL;

            CHECK_OBJECT((PyObject *)tmp_for_loop_3__for_iterator);
            Py_DECREF(tmp_for_loop_3__for_iterator);
            tmp_for_loop_3__for_iterator = NULL;

            // Re-raise.
            exception_type = exception_keeper_type_3;
            exception_value = exception_keeper_value_3;
            exception_tb = exception_keeper_tb_3;
            exception_lineno = exception_keeper_lineno_3;

            goto try_except_handler_3;
            // End of try:
            try_end_2:;
            Py_XDECREF(tmp_for_loop_3__iter_value);
            tmp_for_loop_3__iter_value = NULL;

            CHECK_OBJECT((PyObject *)tmp_for_loop_3__for_iterator);
            Py_DECREF(tmp_for_loop_3__for_iterator);
            tmp_for_loop_3__for_iterator = NULL;

            branch_no_8:;
        }
        if (CONSIDER_THREADING() == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 50;

            goto try_except_handler_3;
        }
        goto loop_start_3;
        loop_end_3:;
        goto try_end_3;
        // Exception handler code:
        try_except_handler_3:;
        exception_keeper_type_4 = exception_type;
        exception_keeper_value_4 = exception_value;
        exception_keeper_tb_4 = exception_tb;
        exception_keeper_lineno_4 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        Py_XDECREF(tmp_for_loop_2__iter_value);
        tmp_for_loop_2__iter_value = NULL;

        CHECK_OBJECT((PyObject *)tmp_for_loop_2__for_iterator);
        Py_DECREF(tmp_for_loop_2__for_iterator);
        tmp_for_loop_2__for_iterator = NULL;

        // Re-raise.
        exception_type = exception_keeper_type_4;
        exception_value = exception_keeper_value_4;
        exception_tb = exception_keeper_tb_4;
        exception_lineno = exception_keeper_lineno_4;

        goto frame_exception_exit_1;
        // End of try:
        try_end_3:;
        Py_XDECREF(tmp_for_loop_2__iter_value);
        tmp_for_loop_2__iter_value = NULL;

        CHECK_OBJECT((PyObject *)tmp_for_loop_2__for_iterator);
        Py_DECREF(tmp_for_loop_2__for_iterator);
        tmp_for_loop_2__for_iterator = NULL;

        branch_end_4:;
    }

    // Restore frame exception if necessary.
#if 0
    RESTORE_FRAME_EXCEPTION(frame_2fed2079e999b99c6812552efed77f38);
#endif
    popFrameStack();

    assertFrameObject(frame_2fed2079e999b99c6812552efed77f38);

    goto frame_no_exception_1;

    frame_exception_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION(frame_2fed2079e999b99c6812552efed77f38);
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK(frame_2fed2079e999b99c6812552efed77f38, exception_lineno);
    }
    else if (exception_tb->tb_frame != &frame_2fed2079e999b99c6812552efed77f38->m_frame) {
        exception_tb = ADD_TRACEBACK(exception_tb, frame_2fed2079e999b99c6812552efed77f38, exception_lineno);
    }

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto module_exception_exit;

    frame_no_exception_1:;

    return module___main__;
    module_exception_exit:
    RESTORE_ERROR_OCCURRED(exception_type, exception_value, exception_tb);
    return NULL;
}
