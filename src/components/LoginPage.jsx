import { useState } from 'react';
import { useNavigate } from 'react-router-dom';

const LoginPage = () => {
  const navigate = useNavigate();
  const [formData, setFormData] = useState({
    email: '',
    password: ''
  });
  const [errors, setErrors] = useState({});
  const [showPassword, setShowPassword] = useState(false);

  const validateEmail = (email) => {
    const emailRegex = /^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$/i;
    return emailRegex.test(email);
  };

  const validateForm = () => {
    const newErrors = {};
    if (!formData.email) {
      newErrors.email = 'Email is required';
    } else if (!validateEmail(formData.email)) {
      newErrors.email = 'Invalid email address';
    }
    if (!formData.password) {
      newErrors.password = 'Password is required';
    } else if (formData.password.length < 6) {
      newErrors.password = 'Password must be at least 6 characters';
    }
    setErrors(newErrors);
    return Object.keys(newErrors).length === 0;
  };

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData(prevState => ({
      ...prevState,
      [name]: value
    }));
    if (errors[name]) {
      setErrors(prev => ({
        ...prev,
        [name]: ''
      }));
    }
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    if (validateForm()) {
      // Simulate authentication
      if (formData.email === 'arjunkamath143@gmail.com' && formData.password === 'Arjun@123') {
        // Store auth token or user data in localStorage/context if needed
        localStorage.setItem('isAuthenticated', 'true');
        navigate('/data');
      } else {
        setErrors({ auth: 'Invalid email or password' });
      }
    }
  };

  return (
    <div className="min-h-screen flex items-center justify-center px-4">
      <div className="max-w-sm w-full py-12 px-8 bg-gray-800 rounded-3xl shadow-2xl">
        {/* Decorative Circle */}
        <div className="flex justify-center mb-8">
          <div className="w-20 h-20 rounded-full border-2 border-teal-400"></div>
        </div>
        
        {/* Login Header */}
        <div className="text-center mb-10">
          <h2 className="text-2xl font-bold text-white tracking-wider">LOGIN PAGE</h2>
        </div>

        {/* Login Form */}
        <form onSubmit={handleSubmit} className="space-y-6">
          <div className="space-y-5">
            {/* Auth Error Message */}
            {errors.auth && (
              <div className="text-center">
                <p className="text-red-400 text-sm">{errors.auth}</p>
              </div>
            )}

            {/* Email Input */}
            <div>
              <div className="relative">
                <input
                  name="email"
                  type="email"
                  value={formData.email}
                  onChange={handleChange}
                  className="w-full px-4 py-3 bg-transparent border border-gray-600 rounded-full
                           text-white placeholder-gray-400 focus:outline-none focus:border-teal-400
                           focus:ring-1 focus:ring-teal-400 transition-all duration-200"
                  placeholder="EMAIL"
                />
              </div>
              {errors.email && (
                <p className="mt-1 text-sm text-red-400 pl-4">
                  {errors.email}
                </p>
              )}
            </div>

            {/* Password Input */}
            <div>
              <div className="relative">
                <input
                  name="password"
                  type={showPassword ? 'text' : 'password'}
                  value={formData.password}
                  onChange={handleChange}
                  className="w-full px-4 py-3 bg-transparent border border-gray-600 rounded-full
                           text-white placeholder-gray-400 focus:outline-none focus:border-teal-400
                           focus:ring-1 focus:ring-teal-400 transition-all duration-200"
                  placeholder="PASSWORD"
                />
                <button
                  type="button"
                  onClick={() => setShowPassword(!showPassword)}
                  className="absolute right-4 top-1/2 transform -translate-y-1/2 text-gray-400
                           hover:text-white focus:outline-none transition-colors duration-200 text-sm"
                >
                  {showPassword ? 'Hide' : 'Show'}
                </button>
              </div>
              {errors.password && (
                <p className="mt-1 text-sm text-red-400 pl-4">
                  {errors.password}
                </p>
              )}
            </div>
          </div>

          {/* Login Button */}
          <div className="pt-4">
            <button
              type="submit"
              className="w-full flex justify-center py-3 px-4 rounded-full
                       bg-teal-400 hover:bg-teal-500 focus:outline-none focus:ring-2
                       focus:ring-offset-2 focus:ring-teal-400 transition-all duration-200
                       text-gray-900 font-semibold"
            >
              LOGIN
            </button>
          </div>
        </form>
      </div>
    </div>
  );
};

export default LoginPage;